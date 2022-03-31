/**
 * @file         liblava/block/compute_pipeline.cpp
 * @brief        Compute pipeline
 * @authors      Lava Block OÜ and contributors
 * @copyright    Copyright (c) 2018-present, MIT License
 */

#include <liblava/block/compute_pipeline.hpp>

namespace lava {

//-----------------------------------------------------------------------------
void compute_pipeline::bind(VkCommandBuffer cmd_buf) {
    vkCmdBindPipeline(cmd_buf, VK_PIPELINE_BIND_POINT_COMPUTE, vk_pipeline);
}

//-----------------------------------------------------------------------------
bool compute_pipeline::set_shader_stage(cdata::ref data, VkShaderStageFlagBits stage) {
    if (!data.ptr) {
        log()->error("compute pipeline shader stage data");
        return false;
    }

    auto shader_stage = create_pipeline_shader_stage(device, data, stage);
    if (!shader_stage) {
        log()->error("create compute pipeline shader stage");
        return false;
    }

    set(shader_stage);
    return true;
}

//-----------------------------------------------------------------------------
bool compute_pipeline::create_internal() {
    VkComputePipelineCreateInfo const create_info{
        .sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO,
        .stage = shader_stage->get_create_info(),
        .layout = layout->get(),
        .basePipelineHandle = 0,
        .basePipelineIndex = -1,
    };

    std::array<VkComputePipelineCreateInfo, 1> const info = { create_info };

    return check(device->call().vkCreateComputePipelines(device->get(), pipeline_cache, to_ui32(info.size()),
                                                         info.data(), memory::alloc(), &vk_pipeline));
}

//-----------------------------------------------------------------------------
void compute_pipeline::destroy_internal() {
    shader_stage = nullptr;
}

//-----------------------------------------------------------------------------
void compute_pipeline::copy_to(compute_pipeline* target) const {
    target->set_layout(layout);

    target->shader_stage = shader_stage;
}

} // namespace lava
