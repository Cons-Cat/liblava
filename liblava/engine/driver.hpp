/**
 * @file         liblava/engine/driver.hpp
 * @brief        Stage driver
 * @authors      Lava Block OÜ and contributors
 * @copyright    Copyright (c) 2018-present, MIT License
 */

#pragma once

#include <argh.h>
#include <liblava/core/types.hpp>

namespace lava {

/**
 * @brief Stage
 */
struct stage {
    /// Map of stages
    using map = std::map<index, stage*>;

    /// Stage function
    using func = std::function<i32(argh::parser)>;

    /**
     * @brief Construct a new stage
     *
     * @param id       Stage id
     * @param descr    Stage description
     * @param func     Stage function
     */
    explicit stage(ui32 id, name descr, func func);

    /// Stage id
    index id = 0;

    /// Stage description
    string descr;

    /// Called on stage run
    func on_func;
};

/**
 * @brief Stage driver
 */
struct driver {
    /**
     * @brief Get driver singleton
     *
     * @return driver&    Stage driver
     */
    static driver& instance() {
        static driver singleton;
        return singleton;
    }

    /**
     * @brief Add a stage
     *
     * @param stage    Stage to add
     */
    void add_stage(stage* stage) {
        stages.emplace(stage->id, stage);
    }

    /**
     * @brief Get all stages
     *
     * @return stage::map const&    Map of stages
     */
    stage::map const& get_stages() const {
        return stages;
    }

    /**
     * @brief Run the driver
     *
     * @param cmd_line    Command line arguments
     *
     * @return i32        Result code
     */
    i32 run(argh::parser cmd_line = {});

private:
    /**
     * @brief Construct a new driver
     */
    driver() = default;

    /// Map of stages
    stage::map stages;
};

/**
 * @brief Run lava (driver)
 *
 * @param cmd_line    Command line arguments
 *
 * @return i32        Result code
 */
inline i32 run(argh::parser cmd_line = {}) {
    return driver::instance().run(cmd_line);
}

} // namespace lava

/// Stage object
#define STAGE_OBJ stage_

/// Stage function
#define STAGE_FUNC _stage

/// String concatenation
#define STR_(n, m) n##m

/// String concatenation
#define STR(n, m) STR_(n, m)

/// Lava stage macro
#define LAVA_STAGE(ID, NAME) \
    i32 STR(STAGE_FUNC, ID)(argh::parser argh); \
    lava::stage STR(STAGE_OBJ, ID)(ID, NAME, ::STR(STAGE_FUNC, ID)); \
    i32 STR(STAGE_FUNC, ID)(argh::parser argh)
