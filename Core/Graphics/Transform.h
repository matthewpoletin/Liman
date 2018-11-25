/**
 * @brief Object transfrom information
 * @file Transform.h
 * @author matthewpoletin
 */

#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform {
public:
	Transform(const glm::vec3 &pos = glm::vec3(), const glm::vec3 &rot = glm::vec3(),
			  const glm::vec3 &scale = glm::vec3(1.0f, 1.0f, 1.0f)) {
		this->pos = pos;
		this->rot = rot;
		this->scale = scale;
	}

	inline glm::mat4 GetModel() const {
		glm::mat4 posMatrix = glm::translate(pos);
		glm::mat4 rotXMatrix = glm::rotate(rot.x, glm::vec3(1, 0, 0));
		glm::mat4 rotYMatrix = glm::rotate(rot.y, glm::vec3(0, 1, 0));
		glm::mat4 rotZMatrix = glm::rotate(rot.z, glm::vec3(0, 0, 1));
		glm::mat4 scaleMatrix = glm::scale(scale);

		glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

		return posMatrix * rotMatrix * scaleMatrix;
	}

	/**
	 * Get position of transform
	 * @return Position of transform
	 */
	inline glm::vec3 &GetPos() { return pos; }

	/**
	 * Get rotation of transform
	 * @return Rotation of transform
	 */
	inline glm::vec3 &GetRot() { return rot; }

	/**
	 * Get scale of transform
	 * @return Scale of transform
	 */
	inline glm::vec3 &GetScale() { return scale; }

	/**
	 * Set position of transform
	 * @param pos
	 */
	inline void SetPos(const glm::vec3 &pos) { this->pos = pos; }

	/**
	 * Set rotation of transform
	 * @param rot Rotation of transform
	 */
	inline void SetRot(const glm::vec3 &rot) { this->rot = rot; }

	/**
	 * Set scale of transform
	 * @param scale Scale of transform
	 */
	inline void SetScale(const glm::vec3 &scale) { this->scale = scale; }

protected:
private:
	glm::vec3 pos{};
	glm::vec3 rot{};
	glm::vec3 scale{};

};