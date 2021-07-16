#!/bin/bash

for arg in "$@"
do
    case $arg in
        -glsl)
            glslangValidator -V -o fragment.spirv glsl/triangle.glsl.frag
            glslangValidator -V -o vertex.spirv glsl/triangle.glsl.vert
            shift
            ;;
        -hlsl)
            glslangValidator -e main -V -fhlsl_functionality1 -o fragment.spirv -D hlsl/triangle.hlsl.frag
            glslangValidator -e main -V -fhlsl_functionality1 -o vertex.spirv -D hlsl/triangle.hlsl.vert
            shift
    esac
done
