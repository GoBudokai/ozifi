#pragma once

#include "callback.h"

/** This file contains client config declaration.
 * Client config required to construct client.
 * You need to specify all necessary parameters
 * and callbacks. */

namespace NVocal {

struct TClientConfig {
    std::string StateDir;                       // directory with internal state data
    TDataCallback CaptchaAvailableCallback;     // on captcha available (for login, reigster, etc.)
    TLoginCallback LoginResultCallback;         // on login failed / success
    TRegisterCallback RegisterResultCallback;   // on register success / fail
    TBoolCallback ConnectedCallback;            // on connection established / failed
    TNamedCallback CallCallback;                // on incoming call
    TNamedCallback ConferenceCallCallback;      // on incoming conference call
    TNamedCallback ConferenceJoinCallback;      // on join to conference
    TNamedCallback ConferenceLeftCallback;      // on conference left
    TMessageCallback MessageCallback;           // on message received
    TMessageCallback ConferenceMessageCallback; // on conference message received
    TStringCallback FriendRequestCallback;      // on friend request received (friend login)
    TCallBack FriendlistChangedCallback;        // on friendlist changed
};

} // NVocal
