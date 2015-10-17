float4x4 matWorld;
float4x4 matWorldViewProj;
float4 vecSunDir;
float4 vecAmbient;
float4 vecSunColor;

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
	
	float3 light = vecAmbient.rgb + vecSunColor.rgb*abs(dot(normalize(input.normal), vecSunDir.xyz))*1.0f;
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