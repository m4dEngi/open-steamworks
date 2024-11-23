//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#include "Types/SteamTypes.h"
#include "Interface_OSW.h"

CSteamAPILoader::CSteamAPILoader(ESearchOrder eSearchOrder)
{
	m_eSearchOrder = eSearchOrder;
	m_pSteamclient = NULL;
}

CSteamAPILoader::~CSteamAPILoader()
{
	if(m_pSteamclient)
		delete m_pSteamclient;
}

bool CSteamAPILoader::Load()
{
	TryGetSteamDir();
	TryLoadLibraries();

	return m_pSteamclient->IsLoaded();
}

CreateInterfaceFn CSteamAPILoader::GetSteam3Factory()
{
	return (CreateInterfaceFn)m_pSteamclient->GetSymbol("CreateInterface");
}

const char* CSteamAPILoader::GetSteamDir()
{
	return m_szSteamPath;
}
	
const DynamicLibrary* CSteamAPILoader::GetSteamClientModule()
{
	return m_pSteamclient;
}

#ifdef _MSC_VER
	#pragma warning(push) 
	#pragma warning(disable: 4996) 
#endif

void CSteamAPILoader::TryGetSteamDir()
{
#ifdef _WIN32
	HKEY hRegKey;

	bool bFallback = true;
#ifdef _WIN64
	if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Wow6432Node\\Valve\\Steam", 0, KEY_QUERY_VALUE, &hRegKey) == ERROR_SUCCESS)
#else
	if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Valve\\Steam", 0, KEY_QUERY_VALUE, &hRegKey) == ERROR_SUCCESS)
#endif
	{
		DWORD dwLength = sizeof(m_szSteamPath) - 1;
		if(RegQueryValueExA(hRegKey, "InstallPath", NULL, NULL, (BYTE*)m_szSteamPath, &dwLength) == ERROR_SUCCESS)
		{
			m_szSteamPath[dwLength] = '\0';
			bFallback = false;
		}
		RegCloseKey(hRegKey);
	}

	if(bFallback)
	{
		strcpy(m_szSteamPath, ".");
	}
#elif defined(__APPLE_CC__)
	bool bFallback = true;

	if (GetApplicationSupportPath(m_szSteamPath, sizeof(m_szSteamPath)))
	{
		strncat(m_szSteamPath, "/Steam/Steam.AppBundle/Steam/Contents/MacOS/",
			sizeof(m_szSteamPath) - strlen(m_szSteamPath) - 1);
		bFallback = false;
	}

	if (bFallback)
	{
		strcpy(m_szSteamPath, ".");
	}
#elif defined(__linux__)
	bool bFallback = true;

	char* szHome = getpwuid(getuid())->pw_dir;

	strncat(m_szSteamPath, szHome, sizeof(m_szSteamPath) - strlen(m_szSteamPath) - 1);

#ifdef __LP64__
	const char* szSDKPath = "/.steam/sdk64/";
#else
	const char* szSDKPath = "/.steam/sdk32/";
#endif
	strncat(m_szSteamPath, szSDKPath, sizeof(m_szSteamPath) - strlen(m_szSteamPath) - 1);

	struct stat info;
	if (stat(m_szSteamPath, &info) == 0)
	{
		if (S_ISDIR(info.st_mode))
		{
			bFallback = false;
		}
	}

	if (bFallback)
	{
		strcpy(m_szSteamPath, ".");
	}
#endif
}

void CSteamAPILoader::TryLoadLibraries()
{
	if(m_eSearchOrder == k_ESearchOrderLocalFirst)
	{
		m_pSteamclient = new DynamicLibrary(k_cszSteam3LibraryName);

		if(!m_pSteamclient->IsLoaded())
		{
			delete m_pSteamclient;
			m_pSteamclient = NULL;
		}
		else
			return;
	}

#ifdef _WIN32
	// steamclient.dll expects to be able to load tier0_s without an absolute
	// path, so we'll need to add the steam dir to the search path.
	SetDllDirectoryA( m_szSteamPath );
#endif

	char szLibraryPath[k_iPathMaxSize];
	szLibraryPath[sizeof(szLibraryPath) - 1] = '\0';

	snprintf(szLibraryPath, sizeof(szLibraryPath) - 1, "%s/%s", m_szSteamPath, k_cszSteam3LibraryName);
	m_pSteamclient = new DynamicLibrary(szLibraryPath);
}


#ifdef _MSC_VER
	#pragma warning(pop) 
#endif
