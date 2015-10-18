float4x4 matWorld;
float4x4 matWorldViewProj;
float4 vecSunDir;
float4 vecAmbient;
float4 vecSunColor;
float4 vecLightPos[8];
float4 vecLightColor[8];

texture entSkin1;
texture entSkin2;

sampler2D groundTexture = sampler_state
{ 
	Texture = <entSkin1>;
	MipFilter = anisotropic;
	MinFilter = anisotropic;
	MagFilter = anisotropic;
};

sampler2D hillTexture = sampler_state
{ 
	Texture = <entSkin2>;
	MipFilter = anisotropic;
	MinFilter = anisotropic;
	MagFilter = anisotropic;
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
	float3 textureCoordinates = input.worldPosition*0.005f;
	float3 colorYZ = tex2D(hillTexture, textureCoordinates.yz);
	float3 colorZX = tex2D(groundTexture, textureCoordinates.zx);
	float3 colorXY = tex2D(hillTexture, textureCoordinates.xy);
	
	float3 blendNormal = abs(input.normal);
	blendNormal = (blendNormal - 0.3)*7;
	blendNormal = max(blendNormal, 0);
	blendNormal /= (blendNormal.x + blendNormal.y + blendNormal.z).xxx;
	
	float4 color;
	color.xyz = colorYZ*blendNormal.xxx + colorZX*blendNormal.yyy + colorXY*blendNormal.zzz;
	color.a = 1.0f;
	
	float light1Attenuation = (vecLightPos[0].w > 10000.0f)? 0.0f : saturate(1.0f-distance(input.worldPosition, vecLightPos[0])/vecLightPos[0].w);
	
	float3 light = float3(0.5f, 0.5f, 0.5f) + vecSunColor.rgb*abs(dot(normalize(input.normal), vecSunDir.xyz))*0.5f + vecLightColor[0].rgb*light1Attenuation;
	color.rgb *= light;
	
	return color;
}


technique terrain
{
	pass p0
	{
		ZWriteEnable = true;
		VertexShader = compile vs_3_0 VS();
		PixelShader = compile ps_3_0 PS();
	}
}