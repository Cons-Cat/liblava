/**
 * @file         liblava/fwd.hpp
 * @brief        Forward declarations
 * @authors      Lava Block OÜ and contributors
 * @copyright    Copyright (c) 2018-present, MIT License
 */

#pragma once

namespace lava {

// liblava/app.hpp
struct app;
struct camera;
struct forward_shading;
struct imgui;

// liblava/asset.hpp
struct image_data;

// liblava/base.hpp
struct target_callback;
struct vk_result;
struct device_table;
struct device_manager;
struct device;
struct instance_info;
struct instance;
struct allocator;
struct memory;
struct physical_device;

// liblava/block.hpp
struct attachment;
struct command;
struct block;
struct descriptor;
struct pipeline_layout;
struct pipeline;
struct graphics_pipeline;
struct compute_pipeline;
struct render_pass;
struct subpass;
struct subpass_dependency;

// liblava/core.hpp
struct data_provider;
struct data;
struct cdata;
struct unique_data;
struct id;
struct ids;
struct entity;
struct rect;
struct timer;
struct run_time;
struct no_copy_no_move;
struct interface;
struct internal_version;
struct version;

// liblava/file.hpp
struct file_guard;
struct file_system;
struct file;
struct file_data;
struct file_callback;
struct json_file;

// liblava/frame.hpp
struct frame_config;
struct frame;
struct key_event;
struct scroll_offset;
struct scroll_event;
struct mouse_position;
struct mouse_move_event;
struct mouse_button_event;
struct mouse_active_event;
struct input_callback;
struct input;
struct gamepad;
struct gamepad_manager;
struct render_target;
struct render_thread;
struct renderer;
struct swapchain;
struct window;

// liblava/resource.hpp
struct buffer;
struct image;
struct vertex;
struct mesh_data;
struct mesh;
struct mesh_meta;
struct file_format;
struct texture;
struct staging;

// liblava/util.hpp
struct log_config;
struct random_generator;
struct pseudo_random_generator;
struct telegram;
struct dispatcher;
struct thread_pool;

} // namespace lava
