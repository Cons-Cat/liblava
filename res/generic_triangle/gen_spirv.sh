#!/bin/bash

for arg in "$@"
do
    case $arg in
        -glsl)
            glslangValidator -V -o triangle_frag.spirv glsl/triangle.glsl.frag
            glslangValidator -V -o lava_triangle.spirv glsl/lava_triangle.glsl.vert
            glslangValidator -V -o int_triangle.spirv glsl/int_triangle.glsl.vert
            glslangValidator -V -o double_triangle.spirv glsl/double_triangle.glsl.vert
            shift
            ;;
        -hlsl)
            glslangValidator -e main -V -fhlsl_functionality1 -o triangle_frag.spirv -D hlsl/triangle.hlsl.frag
            glslangValidator -e main -V -fhlsl_functionality1 -o lava_triangle.spirv -D hlsl/lava_triangle.hlsl.vert
            glslangValidator -e main -V -fhlsl_functionality1 -o int_triangle.spirv -D hlsl/int_triangle.hlsl.vert
            glslangValidator -e main -V -fhlsl_functionality1 -o double_triangle.spirv -D hlsl/double_triangle.hlsl.vert
            shift
    esac
done
