#pragma once
#include <iostream>
#include "Mesh.h"
#include <glm/glm.hpp>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// Character cords
float xWalk = 0.0f;
float zWalk = 3.0f;
float yWalk = 10.0f;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// collision
bool within1stLevelBoxBounds = false;
bool within2ndLevelBoxBounds = false;
float LastWalkx;
float LastWalky;
float LastWalkz;

// moving anim + camera cords
glm::vec3 CameraCords = glm::vec3(xWalk, yWalk + 2.4f, zWalk + 3.0f);
bool ismoving = true;
float Rotate = 180.0f;

// jump
bool AlreadyJumped = false;
int jumpLength = 0;
bool isjumping = false;

// jumping variables
float yVelocity = 0.f;
float yGravity = -3.f;
float JumpInitVelocity = 2.7f;

float skyboxVertices[] = {
    // positions 

    -1.0f,  1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

    -1.0f,  1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f,  1.0f
};
float CubeVertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};
std::vector<Vertex> PlaneVertices {
    Vertex { glm::vec3(5.0f, -0.5f, 5.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f), glm::vec3(0.0f) },
    Vertex { glm::vec3(5.0f, -0.5f, -5.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f), glm::vec3(0.0f) },
    Vertex { glm::vec3(-5.0f, -0.5f, -5.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f), glm::vec3(0.0f) },
    Vertex { glm::vec3(-5.0f, -0.5f, 5.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f), glm::vec3(0.0f) }
};
std::vector<unsigned int> PlaneIndices {
    0, 1, 3,
    1, 2, 3
};
void CheckCollision(float DeltaTime)
{
    within1stLevelBoxBounds = false;
    within2ndLevelBoxBounds = false;
    if(zWalk >= -0.5f && zWalk <= 0.5f && xWalk >= -0.5f && xWalk <= 0.5f)
    {
        within1stLevelBoxBounds = true;
    }
    if(zWalk >= 0.5f && zWalk <= 1.5f && xWalk >= 0.5f && xWalk <= 1.5f)
    {
        within1stLevelBoxBounds = true;
    }
    if(zWalk >= -0.5f && zWalk <= 0.5f && xWalk >= 0.5f && xWalk <= 1.5f)
    {
        within1stLevelBoxBounds = true;
    }
    if(zWalk >= 0.5f && zWalk <= 1.5f && xWalk >= -0.5f && xWalk <= 0.5f)
    {
        within1stLevelBoxBounds = true;
    }
    if(zWalk >= -0.5f && zWalk <= 0.5f && xWalk >= -1.5f && xWalk <= -0.5f)
    {
        within1stLevelBoxBounds = true;
    }
    if(zWalk <= 0.5f && zWalk >= -0.5f && xWalk <= 1.85f && xWalk >= 0.85f)
    {
        within2ndLevelBoxBounds = true;
    }

    // Check for collision
    if (yWalk < 1.0f) {
        if (within1stLevelBoxBounds) {
            xWalk = LastWalkx;
            zWalk = LastWalkz;
            within1stLevelBoxBounds = false;
        }
    }

    if (yWalk > 0.97f && yWalk < 2.0f && within2ndLevelBoxBounds)
    {
        xWalk = LastWalkx;
        zWalk = LastWalkz;
        within2ndLevelBoxBounds = false;
    }

    if (within2ndLevelBoxBounds) {
        if (yWalk <= 2.07f && !isjumping) {
            yVelocity = 0.0f;
            AlreadyJumped = false;
            yWalk = 2.0f;
        }
    } else {
        if (yWalk < 0.0f) {
            yVelocity = 0.0f;
            AlreadyJumped = false;    
            yWalk = 0.0f;
        }
    }
    // Check floor height
    if (within1stLevelBoxBounds) {
        if (yWalk <= 1.07f && !isjumping) {
            yVelocity = 0.0f;
            AlreadyJumped = false;
            yWalk = 1.0f;
        }
    } else {
        if (yWalk < 0.0f) {
            yVelocity = 0.0f;
            AlreadyJumped = false;    
            yWalk = 0.0f;
        }
    }

    yWalk += yVelocity * DeltaTime;
}
glm::vec2 ProcessInput(GLFWwindow* window, glm::vec2 direction)
{
    // Step 1. Process input
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        direction += glm::vec2(-1.0f, 0.0f);
        ismoving = true;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        direction += glm::vec2(1.0f, 0.0f);
        ismoving = true;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        direction += glm::vec2(0.0f, -1.0f);
        ismoving = true;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        direction += glm::vec2(0.0f, 1.0f);
        ismoving = true;            
    }

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        if(!AlreadyJumped)
        {
            isjumping = true;
            AlreadyJumped = true;
        }
        jumpLength++;
    } else {
        isjumping = false;
        jumpLength = 0;
    }

    return direction;
}
void CheckRotation(glm::vec2 direction)
{
    // Step 2. Figure out rotation of model
        if (glm::length(direction) > 0.0f) 
        {

        // 1. Normalize to length 1.0
        direction = glm::normalize(direction);

        // 2. Calculate the movement
        zWalk += direction.x * 0.69f * deltaTime;
        xWalk += direction.y * 0.69f * deltaTime;

        // 3. Calculate the intended angle
        auto needed_rotation = glm::acos(glm::dot(direction, glm::vec2(1.0f, 0.0f)));
        if (direction.y != 0.0f)
            needed_rotation *= abs(direction.y) / direction.y;
        auto amount = 0.0f;

        //4. Rotate to intended angle
        if (Rotate > glm::degrees(needed_rotation))
            amount -= 360.0f * deltaTime;
        if (Rotate < glm::degrees(needed_rotation))
            amount += 360.0f * deltaTime;

        Rotate += amount;

        // 5. NO VIBRATING!
        if(amount > 0.0f && Rotate > glm::degrees(needed_rotation))
            Rotate = glm::degrees(needed_rotation);
        if(amount < 0.0f && Rotate < glm::degrees(needed_rotation))
            Rotate = glm::degrees(needed_rotation);
    }
}
void CheckJumping()
{
    // Step 3. Sort out jumping
    if(jumpLength > 10)
        isjumping = false;

    // Check if now jumping?
    if (isjumping)
    {
        yVelocity = JumpInitVelocity;
    }
    // Apply gravity with Euler integration
    yVelocity += yGravity * deltaTime;
}

/*float PlaneVertices[] = {
    // positions          // texture coords
     5.f,  5.f, 0.f,   1.0f, 1.0f, // top right
     5.f, -5.f, 0.f,   1.0f, 0.0f, // bottom right
    -5.f, -5.f, 0.f,   0.0f, 0.0f, // bottom left
    -5.f,  5.f, 0.f,   0.0f, 1.0f  // top left 
};*/
/*unsigned int PlaneIndices[] = {
   0, 1, 3, // first triangle
   1, 2, 3  // second triangle
};*/