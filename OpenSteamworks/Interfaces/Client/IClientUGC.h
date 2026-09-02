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

#ifndef ICLIENTUGC_H
#define ICLIENTUGC_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Types/UGCCommon.h"
#include "Types/RemoteStorageCommon.h"

abstract_class UNSAFE_INTERFACE IClientUGC
{
public:
    // Query UGC associated with a user. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
    virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage) = 0;
    // Query for all matching UGC. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
    virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage) = 0;
    virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, const char* pchUnk) = 0;
    // Query for the details of the given published file ids (the RequestUGCDetails call is deprecated and replaced with this)
    virtual UGCQueryHandle_t  CreateQueryUGCDetailsRequest(PublishedFileId_t *, uint32) = 0;
    // Send the query to Steam
    virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t handle) = 0;
    // Retrieve an individual result after receiving the callback for querying UGC
    virtual bool GetQueryUGCResult(UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t *pDetails) = 0;
    virtual unknown_ret GetQueryUGCNumTags(UGCQueryHandle_t handle, uint32) = 0;
    virtual unknown_ret GetQueryUGCTag(UGCQueryHandle_t handle, uint32, uint32, char*, uint32) = 0;
    virtual unknown_ret GetQueryUGCTagDisplayName(UGCQueryHandle_t handle, uint32, uint32, char*, uint32) = 0;
    virtual bool GetQueryUGCPreviewURL(UGCQueryHandle_t handle, uint32, char*, uint32) = 0;
    virtual bool GetQueryUGCImageURL(UGCQueryHandle_t handle, uint32, char*, uint32, uint32*, uint32*) = 0;
    virtual bool GetQueryUGCMetadata(UGCQueryHandle_t handle, uint32, char*, uint32) = 0;
    virtual bool GetQueryUGCChildren(UGCQueryHandle_t handle, uint32, PublishedFileId_t*, uint32) = 0;
    virtual bool GetQueryUGCStatistic(UGCQueryHandle_t handle, uint32, EItemStatistic, uint64*) = 0;
    virtual uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t handle, uint32) = 0;
    virtual bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t handle, uint32, uint32, char*, uint32, char*, uint32, EItemPreviewType*) = 0;
    virtual uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t handle, uint32) = 0;
    virtual bool GetQueryUGCKeyValueTag(UGCQueryHandle_t handle, uint32, uint32, char*, uint32, char*, uint32) = 0;
    virtual bool GetQueryUGCKeyValueTag(UGCQueryHandle_t handle, uint32, const char*, char*, uint32) = 0;
    virtual unknown_ret GetQueryUGCContentDescriptors() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetNumSupportedGameVersions() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetSupportedGameVersionData() = 0; //TODO: REVERSE ME
    virtual bool GetQueryUGCIsDepotBuild(UGCQueryHandle_t, uint32, bool*) = 0;
    // Release the request to free up memory, after retrieving results
    virtual bool ReleaseQueryUGCRequest(UGCQueryHandle_t handle) = 0;
    // Options to set for querying UGC
    virtual bool AddRequiredTag(UGCQueryHandle_t handle, const char *pTagName) = 0;
    virtual unknown_ret AddRequiredTagGroup() = 0; //TODO: REVERSE ME
    virtual bool AddExcludedTag(UGCQueryHandle_t handle, const char *pTagName) = 0;
    virtual bool SetReturnOnlyIDs(UGCQueryHandle_t handle, bool bReturnOnlyIDs) = 0;
    virtual bool SetReturnKeyValueTags(UGCQueryHandle_t handle, bool) = 0;
    virtual bool SetReturnLongDescription(UGCQueryHandle_t handle, bool bReturnLongDescription) = 0;
    virtual bool SetReturnMetadata(UGCQueryHandle_t handle, bool) = 0;
    virtual bool SetReturnChildren(UGCQueryHandle_t handle, bool) = 0;
    virtual bool SetReturnAdditionalPreviews(UGCQueryHandle_t handle, bool) = 0;
    virtual bool SetReturnTotalOnly(UGCQueryHandle_t handle, bool bReturnTotalOnly) = 0;
    virtual bool SetReturnPlaytimeStats(UGCQueryHandle_t handle, uint32 unDays) = 0;
    virtual bool SetLanguage(UGCQueryHandle_t handle, const char*) = 0;
    virtual bool SetAllowCachedResponse(UGCQueryHandle_t handle, uint32 unMaxAgeSeconds) = 0;
    virtual unknown_ret SetAdminQuery() = 0; //TODO: REVERSE ME
    // Options only for querying user UGC
    virtual bool SetCloudFileNameFilter(UGCQueryHandle_t handle, const char *pMatchCloudFileName) = 0;
    // Options only for querying all UGC
    virtual bool SetMatchAnyTag(UGCQueryHandle_t handle, bool bMatchAnyTag) = 0;
    virtual bool SetSearchText(UGCQueryHandle_t handle, const char *pSearchText) = 0;
    virtual bool SetRankedByTrendDays(UGCQueryHandle_t handle, uint32 unDays) = 0;
    virtual unknown_ret SetTimeCreatedDateRange() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetTimeUpdatedDateRange() = 0; //TODO: REVERSE ME
    virtual bool AddRequiredKeyValueTag(UGCQueryHandle_t handle, const char*, const char*) = 0;
    // DEPRECATED - Use CreateQueryUGCDetailsRequest call above instead!
    virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds) = 0;
    // Steam Workshop Creator API
    virtual SteamAPICall_t CreateItem(AppId_t nConsumerAppId, EWorkshopFileType eFileType) = 0; //create new item for this app with no content attached yet
    virtual UGCUpdateHandle_t StartItemUpdate(AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID) = 0; //start an UGC item update. Set changed properties before commiting update with CommitItemUpdate()
    virtual bool SetItemTitle(UGCUpdateHandle_t handle, const char *pchTitle) = 0; //change the title of an UGC item
    virtual bool SetItemDescription(UGCUpdateHandle_t handle, const char *pchDescription) = 0; //change the description of an UGC item
    virtual bool SetItemUpdateLanguage(UGCUpdateHandle_t handle, const char*) = 0;
    virtual bool SetItemMetadata(UGCUpdateHandle_t handle, const char*) = 0;
    virtual bool SetItemVisibility(UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility) = 0; //change the visibility of an UGC item
    virtual bool SetItemTags(UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t *pTags) = 0; //change the tags of an UGC item
    virtual bool SetItemContent(UGCUpdateHandle_t handle, const char *pszContentFolder) = 0; //update item content from this local folder
    virtual bool SetItemPreview(UGCUpdateHandle_t handle, const char *pszPreviewFile) = 0; //change preview image file for this item. pszPreviewFile points to local image file, which must be under 1MB in size
    virtual bool SetAllowLegacyUpload(UGCUpdateHandle_t handle, bool) = 0;
    virtual bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t handle) = 0;
    virtual bool RemoveItemKeyValueTags(UGCUpdateHandle_t handle, const char*) = 0;
    virtual bool AddItemKeyValueTag(UGCUpdateHandle_t handle, const char*, const char*) = 0;
    virtual bool AddItemPreviewFile(UGCUpdateHandle_t handle, const char*, EItemPreviewType) = 0;
    virtual bool AddItemPreviewVideo(UGCUpdateHandle_t handle, const char*) = 0;
    virtual bool UpdateItemPreviewFile(UGCUpdateHandle_t handle, uint32, const char*) = 0;
    virtual bool UpdateItemPreviewVideo(UGCUpdateHandle_t handle, uint32, const char*) = 0;
    virtual bool RemoveItemPreview(UGCUpdateHandle_t handle, uint32) = 0;
    virtual unknown_ret AddContentDescriptor() = 0; //TODO: REVERSE ME
    virtual unknown_ret RemoveContentDescriptor() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetRequiredGameVersions() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetExternalAssetID() = 0; //TODO: REVERSE ME
    // Steam Workshop Consumer API
    virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t handle, const char *pchChangeNote) = 0; //commit update process started with StartItemUpdate()
    virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t handle, uint64 *punBytesProcessed, uint64* punBytesTotal) = 0;
    virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t , bool) = 0;
    virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t) = 0;
    virtual SteamAPICall_t AddItemToFavorites(AppId_t, PublishedFileId_t) = 0;
    virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t, PublishedFileId_t) = 0;
    virtual SteamAPICall_t SubscribeItem(AppId_t, PublishedFileId_t nPublishedFileID, bool) = 0; //subscript to this item, will be installed ASAP
    virtual SteamAPICall_t UnsubscribeItem(AppId_t, PublishedFileId_t nPublishedFileID) = 0; //unsubscribe from this item, will be uninstalled after game quits
    virtual uint32 GetNumSubscribedItems(AppId_t) = 0; //number of subscribed items
    virtual uint32 GetSubscribedItems(AppId_t, PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries) = 0; //all subscribed item PublishFileIDs
    virtual unknown_ret GetSubscribedItemsInternal() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetWorkshopItemsDisabledLocally() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetSubscriptionsLoadOrder() = 0; //TODO: REVERSE ME
    virtual unknown_ret MoveSubscriptionsLoadOrder() = 0; //TODO: REVERSE ME
    // get EItemState flags about item on this client
    virtual uint32 GetItemState(AppId_t, PublishedFileId_t) = 0;
    // get info about currently installed content on disc for items that have k_EItemStateInstalled set
    // if k_EItemStateLegacyItem is set, pchFolder contains the path to the legacy file itself (not a folder)
    virtual bool GetItemInstallInfo(AppId_t, PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize, bool *pbLegacyItem) = 0; //returns true if item is installed
    // get info about pending update for items that have k_EItemStateNeedsUpdate set. punBytesTotal will be valid after download started once
    virtual bool GetItemDownloadInfo(AppId_t, PublishedFileId_t , uint64*, uint64*) = 0;
    // download new or update already installed item. If function returns true, wait for DownloadItemResult_t. If the item is already installed,
    // then files on disk should not be used until callback received. If item is not subscribed to, it will be cached for some time.
    // If bHighPriority is set, any other item download will be suspended and this item downloaded ASAP.
    virtual bool DownloadItem(AppId_t, PublishedFileId_t , bool) = 0;
    virtual bool GetAppItemsStatus(AppId_t, bool*, bool*) = 0;
    // game servers can set a specific workshop folder before issuing any UGC commands.
    // This is helpful if you want to support multiple game servers running out of the same install folder
    virtual bool BInitWorkshopForGameServer(AppId_t, DepotId_t, const char*) = 0;
    virtual void SuspendDownloads(AppId_t, bool) = 0;
    virtual uint64 GetAllItemsSizeOnDisk(AppId_t) = 0;
    virtual SteamAPICall_t StartPlaytimeTracking(AppId_t, PublishedFileId_t* publishedFields, uint32 numPublishedFields) = 0;
    virtual SteamAPICall_t StopPlaytimeTracking(AppId_t, PublishedFileId_t* publishedFields, uint32 numPublishedFields) = 0;
    virtual SteamAPICall_t StopPlaytimeTrackingForAllItems(AppId_t) = 0;
    virtual SteamAPICall_t AddDependency(PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID) = 0;
    virtual SteamAPICall_t RemoveDependency(PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID) = 0;
    virtual SteamAPICall_t AddAppDependency(PublishedFileId_t nPublishedFileID, AppId_t nAppID) = 0;
    virtual SteamAPICall_t RemoveAppDependency(PublishedFileId_t nPublishedFileID, AppId_t nAppID) = 0;
    virtual bool GetAppDependencies(PublishedFileId_t nPublishedFileID) = 0;
    virtual SteamAPICall_t DeleteItem(PublishedFileId_t nPublishedFileID) = 0;
    virtual unknown_ret ShowWorkshopEULA() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetWorkshopEULAStatus() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetUserContentDescriptorPreferences() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetItemsDisabledLocally() = 0; //TODO: REVERSE ME
    virtual unknown_ret SetSubscriptionsLoadOrder2() = 0; // TODO: REVERSE ME
    virtual unknown_ret MarkDownloadedItemAsUnused() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetNumDownloadedItems() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetDownloadedItems() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetFullQueryUGCResponse() = 0; //TODO: REVERSE ME
    virtual unknown_ret GetSerializedQueryUGCResponse() = 0; //TODO: REVERSE ME
    virtual unknown_ret BNeedsSteamChinaWorkshop() = 0; //TODO: REVERSE ME
};

#endif // ICLIENTUGC_H
