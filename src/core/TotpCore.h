/*
* Copyright (c) 2003-2023 Rony Shapiro <ronys@pwsafe.org>.
* All rights reserved. Use of the code is allowed under the
* Artistic License 2.0 terms, as specified in the LICENSE file
* distributed with this code, or available from
* http://www.opensource.org/licenses/artistic-license-2.0.php
* Contributed by Ashley R. Thomas, 18-Oct-2023
*/
// TotpCore.h
//-----------------------------------------------------------------------------

#pragma once
#include <string>
#include <stdint.h>


/**
 * Password Safe Core library two factor authentication related structs and
 * funtionality connecting PwSafe Core users (i.e., UI/CLI) with TOTP internals.
 */

const uint32_t TOTP_INVALID_AUTH_CODE = 0;

const uint8_t TOTP_DEFAULT_AUTH_CODE_LENGTH = 6;
const uint8_t TOTP_DEFAULT_TIME_STEP_SECONDS = 30;

// Mask and access information from DB TOTP Config (see formatV3.txt).
const uint8_t TOTP_CONFIG_ALGORITHM_MASK = 0x03;
const uint8_t TOTP_CONFIG_ALGORITHM_HMAC_SHA1 = 0x00;
const uint8_t TOTP_CONFIG_ALGORITHM_DEFAULT = TOTP_CONFIG_ALGORITHM_HMAC_SHA1;

class CItemData;
uint32_t GetNextTotpAuthCode(const CItemData& data, time_t* pBasisTimeNow);
std::string TotpCodeToString(const CItemData& data, uint32_t totp_auth_code);
std::string GetNextTotpAuthCodeString(const CItemData& data, time_t* pBasisTimeNow);