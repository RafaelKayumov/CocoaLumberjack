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

// Disable legacy macros
#ifndef TMP_LEGACY_MACROS
    #define TMP_LEGACY_MACROS 0
#endif

#import <CocoaLumberjack/TMPLog.h>

/**
 * The constant/variable/method responsible for controlling the current log level.
 **/
#ifndef LOG_LEVEL_DEF
    #define LOG_LEVEL_DEF tmpLogLevel
#endif

/**
 * Whether async should be used by log messages, excluding error messages that are always sent sync.
 **/
#ifndef LOG_ASYNC_ENABLED
    #define LOG_ASYNC_ENABLED YES
#endif

/**
 * This is the single macro that all other macros below compile into.
 * This big multiline macro makes all the other macros easier to read.
 **/
#define LOGV_MACRO(isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, avalist) \
        [TMPLog log : isAsynchronous                                          \
             level : lvl                                                     \
              flag : flg                                                     \
           context : ctx                                                     \
              file : __FILE__                                                \
          function : fnct                                                    \
              line : __LINE__                                                \
               tag : atag                                                    \
            format : frmt                                                    \
              args : avalist]

/**
 * Define version of the macro that only execute if the log level is above the threshold.
 * The compiled versions essentially look like this:
 *
 * if (logFlagForThisLogMsg & tmpLogLevel) { execute log message }
 *
 * When LOG_LEVEL_DEF is defined as tmpLogLevel.
 *
 * As shown further below, Lumberjack actually uses a bitmask as opposed to primitive log levels.
 * This allows for a great amount of flexibility and some pretty advanced fine grained logging techniques.
 *
 * Note that when compiler optimizations are enabled (as they are for your release builds),
 * the log messages above your logging threshold will automatically be compiled out.
 *
 * (If the compiler sees LOG_LEVEL_DEF/tmpLogLevel declared as a constant, the compiler simply checks to see
 *  if the 'if' statement would execute, and if not it strips it from the binary.)
 *
 * We also define shorthand versions for asynchronous and synchronous logging.
 **/
#define LOGV_MAYBE(async, lvl, flg, ctx, tag, fnct, frmt, avalist) \
        do { if(lvl & flg) LOGV_MACRO(async, lvl, flg, ctx, tag, fnct, frmt, avalist); } while(0)

/**
 * Ready to use log macros with no context or tag.
 **/
#define TMPLogVError(frmt, avalist)   LOGV_MAYBE(NO,                LOG_LEVEL_DEF, TMPLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, avalist)
#define TMPLogVWarn(frmt, avalist)    LOGV_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, TMPLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, avalist)
#define TMPLogVInfo(frmt, avalist)    LOGV_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, TMPLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, avalist)
#define TMPLogVDebug(frmt, avalist)   LOGV_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, TMPLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, avalist)
#define TMPLogVVerbose(frmt, avalist) LOGV_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, TMPLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, avalist)

