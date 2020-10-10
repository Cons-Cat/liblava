// file      : liblava/file/file.hpp
// copyright : Copyright (c) 2018-present, Lava Block OÜ
// license   : MIT; see accompanying LICENSE file

#pragma once

#include <fstream>
#include <liblava/core/data.hpp>

// fwd
struct PHYSFS_File;

namespace lava {

    enum class file_type : type {
        none = 0,
        fs,
        f_stream
    };

    constexpr i64 const file_error_result = -1;

    inline bool file_error(i64 result) {
        return result == file_error_result;
    }

    struct file : no_copy_no_move {
        explicit file(name path = nullptr, bool write = false);
        ~file();

        bool open(name path, bool write = false);
        void close();

        bool opened() const;
        i64 get_size() const;

        i64 read(data_ptr data) {
            return read(data, to_ui64(get_size()));
        }
        i64 read(data_ptr data, ui64 size);

        i64 write(data_cptr data, ui64 size);

        bool writable() const {
            return write_mode;
        }
        file_type get_type() const {
            return type;
        }

        name get_path() const {
            return path;
        }

    private:
        file_type type = file_type::none;
        bool write_mode = false;

        name path = nullptr;

        PHYSFS_File* fs_file = nullptr;
        mutable std::ifstream i_stream;
        mutable std::ofstream o_stream;
    };

} // namespace lava
