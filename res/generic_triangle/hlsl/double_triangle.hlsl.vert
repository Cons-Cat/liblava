struct in_vertex {
    [[vk::location(0)]] double3 position : POSITION;
    [[vk::location(2)]] float4 color     : COLOR;
};

struct out_pixel {
    float4 position                  : SV_POSITION;
    [[vk::location(0)]] float4 color : COLOR;
};

out_pixel main(in_vertex input) {
    out_pixel output;
    output.position = float4(input.position, 1);
    output.color = input.color;
    return output;
}
