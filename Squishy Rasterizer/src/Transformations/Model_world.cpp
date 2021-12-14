#include "pch.h"
#include "Model_world.h"

namespace tfm
{
    glm::mat4 u_scale(const float scale_factor)
    {
        return glm::scale(identity, glm::vec3(scale_factor));
    }

    glm::mat4 scale(const glm::vec3 scale_vec)
    {
        return glm::scale(identity, scale_vec);
    }

    glm::mat4 rotate_around_wOrigin(const float degrees, const glm::vec3 axis)
    {
        return glm::rotate(identity, glm::radians(degrees), axis);
    }

    glm::mat4 translate(const glm::vec3 displacement)
    {
        return glm::translate(identity, displacement);
    }
}
