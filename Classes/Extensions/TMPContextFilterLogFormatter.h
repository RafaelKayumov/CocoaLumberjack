// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2019, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

#import <Foundation/Foundation.h>

// Disable legacy macros
#ifndef TMP_LEGACY_MACROS
    #define TMP_LEGACY_MACROS 0
#endif

#import <CocoaLumberjack/TMPLog.h>

/**
 * This class provides a log formatter that filters log statements from a logging context not on the whitelist.
 *
 * A log formatter can be added to any logger to format and/or filter its output.
 * You can learn more about log formatters here:
 * Documentation/CustomFormatters.md
 *
 * You can learn more about logging context's here:
 * Documentation/CustomContext.md
 *
 * But here's a quick overview / refresher:
 *
 * Every log statement has a logging context.
 * These come from the underlying logging macros defined in TMPLog.h.
 * The default logging context is zero.
 * You can define multiple logging context's for use in your application.
 * For example, logically separate parts of your app each have a different logging context.
 * Also 3rd party frameworks that make use of Lumberjack generally use their own dedicated logging context.
 **/
@interface TMPContextWhitelistFilterLogFormatter : NSObject <TMPLogFormatter>

/**
 *  Designated default initializer
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 *  Add a context to the whitelist
 *
 *  @param loggingContext the context
 */
- (void)addToWhitelist:(NSInteger)loggingContext;

/**
 *  Remove context from whitelist
 *
 *  @param loggingContext the context
 */
- (void)removeFromWhitelist:(NSInteger)loggingContext;

/**
 *  Return the whitelist
 */
@property (readonly, copy) NSArray<NSNumber *> *whitelist;

/**
 *  Check if a context is on the whitelist
 *
 *  @param loggingContext the context
 */
- (BOOL)isOnWhitelist:(NSInteger)loggingContext;

@end

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * This class provides a log formatter that filters log statements from a logging context on the blacklist.
 **/
@interface TMPContextBlacklistFilterLogFormatter : NSObject <TMPLogFormatter>

- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 *  Add a context to the blacklist
 *
 *  @param loggingContext the context
 */
- (void)addToBlacklist:(NSInteger)loggingContext;

/**
 *  Remove context from blacklist
 *
 *  @param loggingContext the context
 */
- (void)removeFromBlacklist:(NSInteger)loggingContext;

/**
 *  Return the blacklist
 */
@property (readonly, copy) NSArray<NSNumber *> *blacklist;


/**
 *  Check if a context is on the blacklist
 *
 *  @param loggingContext the context
 */
- (BOOL)isOnBlacklist:(NSInteger)loggingContext;

@end
