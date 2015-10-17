float4x4 matWorld;
float4x4 matWorldViewProj;
float4 vecSunDir;
float4 vecAmbient;

texture entSkin1;

sampler2D groundTexture = sampler_state
{ 
	Texture = <entSkin1>;
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

struct VS_OUTPUT
{
	float4 position : POSITION;
	float3 normal : TEXCOORD0;
	float3 worldPosition : TEXCOORD1;
};

VS_OUTPUT VS(float4 position : POSITION, float3 normal : NORMAL)
{
	VS_OUTPUT output = (VS_OUTPUT)0;
	
	output.position = mul(position, matWorldViewProj);
	output.normal = mul(normal, matWorld);
	output.worldPosition = mul(position, matWorld).xyz;
	
	return output;
}

float4 PS(VS_OUTPUT input) : COLOR
{
	float3 textureCoordinates = input.worldPosition*0.1f;
	float3 colorXZ = tex2D(groundTexture, textureCoordinates.xz);
	float3 colorXY = tex2D(groundTexture, textureCoordinates.xy);
	float3 colorYZ = tex2D(groundTexture, textureCoordinates.yz);
	
	float3 blendNormal = saturate(pow(abs(normalize(input.normal))*1.5f, 6.0f));
	
	float4 color;
	color.xyz = lerp(lerp(colorXY, colorYZ, blendNormal.z), colorXZ, blendNormal.y);
	color.a = 1.0f;
	
	return color;
}


technique terrain
{
	pass p0
	{
		VertexShader = compile vs_3_0 VS();
		PixelShader = compile ps_3_0 PS();
	}
}