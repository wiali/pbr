#pragma once

#include <glm/glm.hpp>

class Light 
{
public:	
	explicit Light(glm::vec3 position);

	glm::vec3 position;
};