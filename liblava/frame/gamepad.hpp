/**
 * @file liblava/frame/gamepad.hpp
 * @brief Gamepad manager
 * @authors Lava Block OÜ and contributors
 * @copyright Copyright (c) 2018-present, MIT License
 */

#pragma once

#include <liblava/core/id.hpp>

namespace lava {

/**
 * @brief Gamepad id
 */
enum class gamepad_id : ui32 {
    _1 = 0,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
    _9,
    _10,
    _11,
    _12,
    _13,
    _14,
    _15,
    _16,

    last = _16,
};

/**
 * @brief Gamepad button
 */
enum class gamepad_button : type {
    a = 0,
    b,
    x,
    y,

    left_bumper,
    right_bumper,

    back,
    start,
    guide,

    left_thumb,
    right_thumb,

    dpad_up,
    dpad_right,
    dpad_down,
    dpad_left,

    last = dpad_left,

    cross = a,
    circle = b,
    square = x,
    triangle = y,
};

/**
 * @brief Gamepad axis
 */
enum class gamepad_axis : type {
    left_x = 0,
    left_y,

    right_x,
    right_y,

    left_trigger,
    right_trigger,

    last = right_trigger,
};

/**
 * @brief Gamepad
 */
struct gamepad {
    /// List of gamepads
    using list = std::vector<gamepad>;

    /// Reference to gamepad
    using ref = gamepad const&;

    /**
     * @brief Construct a new gamepad
     * 
     * @param id Gamepad id
     */
    explicit gamepad(gamepad_id id);

    /**
     * @brief Check if gamepad is active
     * 
     * @return true Gamepad is active
     * @return false Gamepad is inactive
     */
    bool ready() const;

    /**
     * @brief Update gamepad
     * 
     * @return true Update was successful
     * @return false Update failed
     */
    bool update();

    /**
     * @brief Check if gamepad button is pressed
     * 
     * @param button Gamepad button to check
     * @return true Button is pressed
     * @return false Button is not pressed
     */
    bool pressed(gamepad_button button) const {
        return state.buttons[to_ui32(button)];
    }

    /**
     * @brief Get value of axis
     * 
     * @param axis Target axis
     * @return r32 Axis value
     */
    r32 value(gamepad_axis axis) const {
        return state.axes[to_ui32(axis)];
    }

    /**
     * @brief Get the gamepad id
     * 
     * @return gamepad_id Gamepad id
     */
    gamepad_id get_pad_id() const {
        return id;
    }

    /**
     * @brief Get the gamepad id as integer
     * 
     * @return ui32 Integer gamepad id
     */
    ui32 get_id() const {
        return to_ui32(get_pad_id());
    }

    /**
     * @brief Get the name
     * 
     * @return name Name of gamepad
     */
    name get_name() const;

private:
    /// Gamepad id
    gamepad_id id;

    /**
     * @brief Gamepad state
     */
    struct state {
        /// Gamepad buttons
        unsigned char buttons[15];

        /// Gamepad axes
        r32 axes[6];
    };

    /// Gamepad state
    gamepad::state state;
};

/**
 * @brief Get list of all gamepads
 * 
 * @return gamepad::list List of gamepads
 */
gamepad::list gamepads();

/**
 * @brief Gamepad manager
 */
struct gamepad_manager {
    /// Gamepad listener function
    using listener_func = std::function<bool(gamepad, bool)>;

    /**
     * @brief Add listener
     * 
     * @param listener Gamepad listener function
     * @return id Id of function
     */
    static id add(listener_func listener);

    /**
     * @brief Remove listener
     * 
     * @param id Id of function
     */
    static void remove(id::ref id);

private:
    /**
     * @brief Construct a new gamepad manager
     */
    explicit gamepad_manager();

    /**
     * @brief Get gamepad manager singleton
     * 
     * @return gamepad_manager& Gamepad manager
     */
    static gamepad_manager& instance() {
        static gamepad_manager manager;
        return manager;
    }

    /// Map of gamepad listeners
    using listener_map = std::map<id, listener_func>;

    /// Map of gamepad listeners
    listener_map map;
};

} // namespace lava