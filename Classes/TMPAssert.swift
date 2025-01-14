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

/**
 * Replacement for Swift's `assert` function that will output a log message even when assertions
 * are disabled.
 *
 * - Parameters:
 *   - condition: The condition to test. Unlike `Swift.assert`, `condition` is always evaluated,
 *     even when assertions are disabled.
 *   - message: A string to log (using `TMPLogError`) if `condition` evaluates to `false`.
 *     The default is an empty string.
 */
@inlinable
public func TMPAssert(_ condition: @autoclosure () -> Bool, _ message: @autoclosure () -> String = "", level: TMPLogLevel = TMPDefaultLogLevel, context: Int = 0, file: StaticString = #file, function: StaticString = #function, line: UInt = #line, tag: Any? = nil, asynchronous async: Bool = false, tmplog: TMPLog = TMPLog.sharedInstance) {
    if !condition() {
        TMPLogError(message(), level: level, context: context, file: file, function: function, line: line, tag: tag, asynchronous: async, tmplog: tmplog)
        Swift.assertionFailure(message(), file: file, line: line)
    }
}

/**
 * Replacement for Swift's `assertionFailure` function that will output a log message even
 * when assertions are disabled.
 *
 * - Parameters:
 *   - message: A string to log (using `TMPLogError`). The default is an empty string.
 */
@inlinable
public func TMPAssertionFailure(_ message: @autoclosure () -> String = "", level: TMPLogLevel = TMPDefaultLogLevel, context: Int = 0, file: StaticString = #file, function: StaticString = #function, line: UInt = #line, tag: Any? = nil, asynchronous async: Bool = false, tmplog: TMPLog = TMPLog.sharedInstance) {
    TMPLogError(message(), level: level, context: context, file: file, function: function, line: line, tag: tag, asynchronous: async, tmplog: tmplog)
    Swift.assertionFailure(message(), file: file, line: line)
}
