#include "Material.h"

PhongMaterial::PhongMaterial(float specular, float diffuse, float ambient, float shininess)
	: matSpecular(specular), matDiffuse(diffuse), matAmbient(ambient), matShininess(shininess) {}

bool PhongMaterial::Scatter(const Ray& in, glm::vec3 normal, ScatterInfo& scatterInfo) const
{
	// phongmaterial generates ray direction favoring the normal
	glm::vec3 scatterRand = RayFunc::randomUnifDist();
	glm::vec3 scatterDir = glm::normalize(normal + scatterRand);
	
	float specularity = glm::dot(scatterDir, normal);
	float diffusity = 1 - specularity;
	
	scatterInfo.scattered.direction = scatterDir;
	scatterInfo.attenuation = scatterInfo.attenuation * matDiffuse * diffusity + scatterInfo.attenuation * matSpecular * specularity ;
	
    return false;
}

GlassMaterial::GlassMaterial(float refractiveIndex)
	: refractiveIndex(refractiveIndex) {}

bool GlassMaterial::Scatter(const Ray& in, glm::vec3 normal, ScatterInfo& scatterInfo) const
{
    return false;
}

Metal::Metal(float shininess, float fuzziness)
	: shininess(shininess), fuzziness(fuzziness) {}

bool Metal::Scatter(const Ray& in, glm::vec3 normal, ScatterInfo& scatterInfo) const
{
	scatterInfo.attenuation *= shininess;
	scatterInfo.scattered.direction = glm::reflect(in.direction, normal);
	return false;
}
