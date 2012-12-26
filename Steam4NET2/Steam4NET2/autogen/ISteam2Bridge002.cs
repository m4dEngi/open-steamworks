// This file is automatically generated.
using System;
using System.Text;
using System.Runtime.InteropServices;

namespace Steam4NET
{

	[StructLayout(LayoutKind.Sequential,Pack=4)]
	public class ISteam2Bridge002VTable
	{
		public IntPtr SetSteam2Ticket0;
		public IntPtr SetAccountName1;
		public IntPtr SetPassword2;
		public IntPtr SetAccountCreationTime3;
		public IntPtr CreateProcess4;
		public IntPtr GetConnectedUniverse5;
		public IntPtr GetIPCountry6;
		public IntPtr GetNumLicenses7;
		public IntPtr GetLicensePackageID8;
		public IntPtr GetLicenseTimeCreated9;
		public IntPtr GetLicenseTimeNextProcess10;
		public IntPtr GetLicenseMinuteLimit11;
		public IntPtr GetLicenseMinutesUsed12;
		public IntPtr GetLicensePaymentMethod13;
		public IntPtr GetLicenseFlags14;
		public IntPtr GetLicensePurchaseCountryCode15;
		public IntPtr SetOfflineMode16;
		public IntPtr GetCurrentSessionToken17;
		public IntPtr SetCellID18;
		public IntPtr SetSteam2FullASTicket19;
		public IntPtr BUpdateAppOwnershipTicket20;
		public IntPtr GetAppOwnershipTicketLength21;
		public IntPtr GetAppOwnershipTicketData22;
		public IntPtr GetAppDecryptionKey23;
		public IntPtr GetPlatformName24;
		public IntPtr GetSteam2FullASTicket25;
		public IntPtr SetWinningPingTimeForCellID26;
		public IntPtr GetSteam2ID27;
		private IntPtr DTorISteam2Bridge00228;
	};
	
	[InteropHelp.InterfaceVersion("STEAM2BRIDGE_INTERFACE_VERSION002")]
	public class ISteam2Bridge002 : InteropHelp.NativeWrapper<ISteam2Bridge002VTable>
	{
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate void NativeSetSteam2TicketBI( IntPtr thisptr, Byte[] pubTicket, Int32 cubTicket );
		public void SetSteam2Ticket( Byte[] pubTicket ) 
		{
			this.GetFunction<NativeSetSteam2TicketBI>( this.Functions.SetSteam2Ticket0 )( this.ObjectAddress, pubTicket, (Int32) pubTicket.Length ); 
		}
		
		[return: MarshalAs(UnmanagedType.I1)]
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate bool NativeSetAccountNameS( IntPtr thisptr, string pchAccountName );
		public bool SetAccountName( string pchAccountName ) 
		{
			return this.GetFunction<NativeSetAccountNameS>( this.Functions.SetAccountName1 )( this.ObjectAddress, pchAccountName ); 
		}
		
		[return: MarshalAs(UnmanagedType.I1)]
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate bool NativeSetPasswordS( IntPtr thisptr, string pchPassword );
		public bool SetPassword( string pchPassword ) 
		{
			return this.GetFunction<NativeSetPasswordS>( this.Functions.SetPassword2 )( this.ObjectAddress, pchPassword ); 
		}
		
		[return: MarshalAs(UnmanagedType.I1)]
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate bool NativeSetAccountCreationTimeU( IntPtr thisptr, UInt32 rt );
		public bool SetAccountCreationTime( UInt32 rt ) 
		{
			return this.GetFunction<NativeSetAccountCreationTimeU>( this.Functions.SetAccountCreationTime3 )( this.ObjectAddress, rt ); 
		}
		
		[return: MarshalAs(UnmanagedType.I1)]
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate bool NativeCreateProcessBUSSUBSU( IntPtr thisptr, Byte[] lpVACBlob, UInt32 cbBlobSize, string lpApplicationName, StringBuilder lpCommandLine, UInt32 dwCreationFlags, Byte[] lpEnvironment, StringBuilder lpCurrentDirectory, UInt32 nGameID );
		public bool CreateProcess( Byte[] lpVACBlob, string lpApplicationName, StringBuilder lpCommandLine, UInt32 dwCreationFlags, Byte[] lpEnvironment, StringBuilder lpCurrentDirectory, UInt32 nGameID ) 
		{
			return this.GetFunction<NativeCreateProcessBUSSUBSU>( this.Functions.CreateProcess4 )( this.ObjectAddress, lpVACBlob, (UInt32) lpVACBlob.Length, lpApplicationName, lpCommandLine, dwCreationFlags, lpEnvironment, lpCurrentDirectory, nGameID ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate EUniverse NativeGetConnectedUniverse( IntPtr thisptr );
		public EUniverse GetConnectedUniverse(  ) 
		{
			return this.GetFunction<NativeGetConnectedUniverse>( this.Functions.GetConnectedUniverse5 )( this.ObjectAddress ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate string NativeGetIPCountry( IntPtr thisptr );
		public string GetIPCountry(  ) 
		{
			return InteropHelp.DecodeANSIReturn( this.GetFunction<NativeGetIPCountry>( this.Functions.GetIPCountry6 )( this.ObjectAddress ) ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate UInt32 NativeGetNumLicenses( IntPtr thisptr );
		public UInt32 GetNumLicenses(  ) 
		{
			return this.GetFunction<NativeGetNumLicenses>( this.Functions.GetNumLicenses7 )( this.ObjectAddress ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate Int32 NativeGetLicensePackageIDU( IntPtr thisptr, UInt32 nLicenseIndex );
		public Int32 GetLicensePackageID( UInt32 nLicenseIndex ) 
		{
			return this.GetFunction<NativeGetLicensePackageIDU>( this.Functions.GetLicensePackageID8 )( this.ObjectAddress, nLicenseIndex ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate UInt32 NativeGetLicenseTimeCreatedU( IntPtr thisptr, UInt32 nLicenseIndex );
		public UInt32 GetLicenseTimeCreated( UInt32 nLicenseIndex ) 
		{
			return this.GetFunction<NativeGetLicenseTimeCreatedU>( this.Functions.GetLicenseTimeCreated9 )( this.ObjectAddress, nLicenseIndex ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate UInt32 NativeGetLicenseTimeNextProcessU( IntPtr thisptr, UInt32 nLicenseIndex );
		public UInt32 GetLicenseTimeNextProcess( UInt32 nLicenseIndex ) 
		{
			return this.GetFunction<NativeGetLicenseTimeNextProcessU>( this.Functions.GetLicenseTimeNextProcess10 )( this.ObjectAddress, nLicenseIndex ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate Int32 NativeGetLicenseMinuteLimitU( IntPtr thisptr, UInt32 nLicenseIndex );
		public Int32 GetLicenseMinuteLimit( UInt32 nLicenseIndex ) 
		{
			return this.GetFunction<NativeGetLicenseMinuteLimitU>( this.Functions.GetLicenseMinuteLimit11 )( this.ObjectAddress, nLicenseIndex ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate Int32 NativeGetLicenseMinutesUsedU( IntPtr thisptr, UInt32 nLicenseIndex );
		public Int32 GetLicenseMinutesUsed( UInt32 nLicenseIndex ) 
		{
			return this.GetFunction<NativeGetLicenseMinutesUsedU>( this.Functions.GetLicenseMinutesUsed12 )( this.ObjectAddress, nLicenseIndex ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate EPaymentMethod NativeGetLicensePaymentMethodU( IntPtr thisptr, UInt32 nLicenseIndex );
		public EPaymentMethod GetLicensePaymentMethod( UInt32 nLicenseIndex ) 
		{
			return this.GetFunction<NativeGetLicensePaymentMethodU>( this.Functions.GetLicensePaymentMethod13 )( this.ObjectAddress, nLicenseIndex ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate ELicenseFlags NativeGetLicenseFlagsU( IntPtr thisptr, UInt32 nLicenseIndex );
		public ELicenseFlags GetLicenseFlags( UInt32 nLicenseIndex ) 
		{
			return this.GetFunction<NativeGetLicenseFlagsU>( this.Functions.GetLicenseFlags14 )( this.ObjectAddress, nLicenseIndex ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate string NativeGetLicensePurchaseCountryCodeU( IntPtr thisptr, UInt32 nLicenseIndex );
		public string GetLicensePurchaseCountryCode( UInt32 nLicenseIndex ) 
		{
			return InteropHelp.DecodeANSIReturn( this.GetFunction<NativeGetLicensePurchaseCountryCodeU>( this.Functions.GetLicensePurchaseCountryCode15 )( this.ObjectAddress, nLicenseIndex ) ); 
		}
		
		[return: MarshalAs(UnmanagedType.I1)]
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate bool NativeSetOfflineModeB( IntPtr thisptr, [MarshalAs(UnmanagedType.I1)] bool bOffline );
		public bool SetOfflineMode( bool bOffline ) 
		{
			return this.GetFunction<NativeSetOfflineModeB>( this.Functions.SetOfflineMode16 )( this.ObjectAddress, bOffline ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate UInt64 NativeGetCurrentSessionToken( IntPtr thisptr );
		public UInt64 GetCurrentSessionToken(  ) 
		{
			return this.GetFunction<NativeGetCurrentSessionToken>( this.Functions.GetCurrentSessionToken17 )( this.ObjectAddress ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate void NativeSetCellIDU( IntPtr thisptr, UInt32 cellID );
		public void SetCellID( UInt32 cellID ) 
		{
			this.GetFunction<NativeSetCellIDU>( this.Functions.SetCellID18 )( this.ObjectAddress, cellID ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate void NativeSetSteam2FullASTicketBI( IntPtr thisptr, Byte[] pubTicket, Int32 cubTicket );
		public void SetSteam2FullASTicket( Byte[] pubTicket ) 
		{
			this.GetFunction<NativeSetSteam2FullASTicketBI>( this.Functions.SetSteam2FullASTicket19 )( this.ObjectAddress, pubTicket, (Int32) pubTicket.Length ); 
		}
		
		[return: MarshalAs(UnmanagedType.I1)]
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate bool NativeBUpdateAppOwnershipTicketUB( IntPtr thisptr, UInt32 nAppID, [MarshalAs(UnmanagedType.I1)] bool bOnlyUpdateIfStale );
		public bool BUpdateAppOwnershipTicket( UInt32 nAppID, bool bOnlyUpdateIfStale ) 
		{
			return this.GetFunction<NativeBUpdateAppOwnershipTicketUB>( this.Functions.BUpdateAppOwnershipTicket20 )( this.ObjectAddress, nAppID, bOnlyUpdateIfStale ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate UInt32 NativeGetAppOwnershipTicketLengthU( IntPtr thisptr, UInt32 nAppID );
		public UInt32 GetAppOwnershipTicketLength( UInt32 nAppID ) 
		{
			return this.GetFunction<NativeGetAppOwnershipTicketLengthU>( this.Functions.GetAppOwnershipTicketLength21 )( this.ObjectAddress, nAppID ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate UInt32 NativeGetAppOwnershipTicketDataUBU( IntPtr thisptr, UInt32 nAppID, Byte[] pvBuffer, UInt32 cubBuffer );
		public UInt32 GetAppOwnershipTicketData( UInt32 nAppID, Byte[] pvBuffer ) 
		{
			return this.GetFunction<NativeGetAppOwnershipTicketDataUBU>( this.Functions.GetAppOwnershipTicketData22 )( this.ObjectAddress, nAppID, pvBuffer, (UInt32) pvBuffer.Length ); 
		}
		
		[return: MarshalAs(UnmanagedType.I1)]
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate bool NativeGetAppDecryptionKeyUBU( IntPtr thisptr, UInt32 nAppID, Byte[] pvBuffer, UInt32 cubBuffer );
		public bool GetAppDecryptionKey( UInt32 nAppID, Byte[] pvBuffer ) 
		{
			return this.GetFunction<NativeGetAppDecryptionKeyUBU>( this.Functions.GetAppDecryptionKey23 )( this.ObjectAddress, nAppID, pvBuffer, (UInt32) pvBuffer.Length ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate string NativeGetPlatformNameB( IntPtr thisptr, ref bool pbIs64Bit );
		public string GetPlatformName( ref bool pbIs64Bit ) 
		{
			return InteropHelp.DecodeANSIReturn( this.GetFunction<NativeGetPlatformNameB>( this.Functions.GetPlatformName24 )( this.ObjectAddress, ref pbIs64Bit ) ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate Int32 NativeGetSteam2FullASTicketBI( IntPtr thisptr, Byte[] pubTicket, Int32 cubTicket );
		public Int32 GetSteam2FullASTicket( Byte[] pubTicket ) 
		{
			return this.GetFunction<NativeGetSteam2FullASTicketBI>( this.Functions.GetSteam2FullASTicket25 )( this.ObjectAddress, pubTicket, (Int32) pubTicket.Length ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate void NativeSetWinningPingTimeForCellIDU( IntPtr thisptr, UInt32 uPing );
		public void SetWinningPingTimeForCellID( UInt32 uPing ) 
		{
			this.GetFunction<NativeSetWinningPingTimeForCellIDU>( this.Functions.SetWinningPingTimeForCellID26 )( this.ObjectAddress, uPing ); 
		}
		
		[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate void NativeGetSteam2IDT( IntPtr thisptr, ref TSteamGlobalUserID pUserID );
		public void GetSteam2ID( ref TSteamGlobalUserID pUserID ) 
		{
			this.GetFunction<NativeGetSteam2IDT>( this.Functions.GetSteam2ID27 )( this.ObjectAddress, ref pUserID ); 
		}
		
	};
}
