//  SDLProxyBase.h
//  Copyright (c) 2015 Ford Motor Company. All rights reserved.

#import "SDLDelegates.h"

enum SDLEvent {OnError, ProxyClosed, ProxyOpened};

@class SDLRPCRequest, SDLRPCResponse, SDLRPCNotification, SDLLanguage, SDLPutFile;


@interface SDLProxyBase : NSObject

// Proxy registration objects
@property (copy) NSString *appName;
@property (copy) NSString *appID;
@property (assign) BOOL isMedia;
@property (strong) SDLLanguage *languageDesired;
@property (copy) NSString *shortName;
@property (copy) NSArray *vrSynonyms;
@property (assign, readonly, getter=isConnected) BOOL connected;

// Methods to add event/RPC notification delegates
// Note: Delegates are NOT run in the main/UI thread. Apps must take this in to account if/when updating the UI from a delegate.
- (void)addOnProxyOpenedDelegate:(id<SDLProxyOpenedDelegate>)delegate;
- (void)addOnProxyClosedDelegate:(id<SDLProxyClosedDelegate>)delegate;
- (void)addFirstHMIFullDelegate:(id<SDLFirstHMIFullDelegate>)delegate;
- (void)addFirstHMINotNoneDelegate:(id<SDLFirstHMINotNoneDelegate>)delegate;
- (void)addProxyErrorDelegate:(id<SDLProxyErrorDelegate>)delegate;
- (void)addAppRegisteredDelegate:(id<SDLAppRegisteredDelegate>)delegate;
- (void)addOnOnLockScreenNotificationDelegate:(id<SDLOnLockScreenNotificationDelegate>)delegate;
- (void)addOnOnLanguageChangeDelegate:(id<SDLOnLanguageChangeDelegate>)delegate;
- (void)addOnOnPermissionsChangeDelegate:(id<SDLOnPermissionsChangeDelegate>)delegate;
- (void)addOnOnDriverDistractionDelegate:(id<SDLOnDriverDistractionDelegate>)delegate;
- (void)addOnOnHMIStatusDelegate:(id<SDLOnHMIStatusDelegate>)delegate;
- (void)addOnOnAppInterfaceUnregisteredDelegate:(id<SDLAppUnregisteredDelegate>)delegate;
- (void)addOnOnAudioPassThruDelegate:(id<SDLOnAudioPassThruDelegate>)delegate;
- (void)addOnOnButtonEventDelegate:(id<SDLOnButtonEventDelegate>)delegate;
- (void)addOnOnButtonPressDelegate:(id<SDLOnButtonPressDelegate>)delegate;
- (void)addOnOnCommandDelegate:(id<SDLOnCommandDelegate>)delegate;
- (void)addOnOnEncodedSyncPDataDelegate:(id<SDLOnEncodedSyncPDataDelegate>)delegate;
- (void)addOnOnHashChangeDelegate:(id<SDLOnHashChangeDelegate>)delegate;
- (void)addOnOnSyncPDataDelegate:(id<SDLOnSyncPDataDelegate>)delegate;
- (void)addOnOnSystemRequestDelegate:(id<SDLOnSystemRequestDelegate>)delegate;
- (void)addOnOnTBTClientStateDelegate:(id<SDLOnTBTClientStateDelegate>)delegate;
- (void)addOnOnTouchEventDelegate:(id<SDLOnTouchEventDelegate>)delegate;
- (void)addOnOnVehicleDataDelegate:(id<SDLOnVehicleDataDelegate>)delegate;

// Main proxy methods
- (void)sendRPC:(SDLRPCRequest *)rpc responseHandler:(RPCResponseHandler)responseHandler;
- (void)startProxyWithAppName:(NSString *)appName appID:(NSString *)appID isMedia:(BOOL)isMedia languageDesired:(SDLLanguage *)languageDesired;
- (void)stopProxy;
- (void)putFileStream:(NSInputStream *)inputStream withRequest:(SDLPutFile *)putFileRPCRequest;

@end