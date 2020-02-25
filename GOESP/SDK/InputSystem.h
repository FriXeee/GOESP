#pragma once

#include "VirtualMethod.h"

class InputSystem {
public:
    constexpr void enableInput(bool enable) noexcept
    {
        VirtualMethod::call<void, 11>(this, enable);
    }

    VIRTUAL_METHOD(resetInputState, void, 39)

    constexpr auto buttonCodeToString(int buttonCode) noexcept
    {
        return VirtualMethod::call<const char*, 40>(this, buttonCode);
    }

    constexpr auto stringToButtonCode(const char* keyName) noexcept
    {
        return VirtualMethod::call<int, 42>(this, keyName);
    }

    // does not support mouse buttons
    constexpr auto virtualKeyToButtonCode(int virtualKey) noexcept
    {
        return VirtualMethod::call<int, 45>(this, virtualKey);
    }

    // does not support mouse buttons
    constexpr auto buttonCodeToVirtualKey(int buttonCode) noexcept
    {
        return VirtualMethod::call<int, 46>(this, buttonCode);
    }

    constexpr auto keyToButtonCode(int key) noexcept
    {
        if (key < 512)
            return virtualKeyToButtonCode(key);

        if (key >= 512 && key <= 518)
            return key - 405;

        return 0;
    }

};
