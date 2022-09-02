//Include:
// glad and glfw
#include "glad/glad.h"
#include <glfw/glfw3.h>

// functions, variables and vectors
#include "main.hpp"

// glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/transform.hpp>

// Model classes
#include "Shader.h" 
#include "Camera.h" 
#include "ModelAnim.h" 
#include "Model.h"
#include "animator.h"

#include <cmath>

// iostream
#include <iostream>
#include <vector>

// window
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

//texture load
unsigned int loadTexture(const char *path);
unsigned int loadCubemap(std::vector<std::string> faces);
unsigned int loadCubeTexture(const char *path);

// Draw cube
void DrawCube(glm::mat4 model, glm::vec3 cords, Shader shader, unsigned int VAO);

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

// main function
int main()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Shader + Objs
    Shader skyboxShader("shaders/skybox.vs", "shaders/skybox.fs");
    Shader shaderAnim("shaders/shaderAnim.vs", "shaders/shader.fs");
    Shader shader("shaders/shader.vs", "shaders/shader.fs");
    Shader cubeShader("shaders/cube.vs", "shaders/cube.fs");
    Shader LightShader("shaders/light.vs", "shaders/light.fs");
    stbi_set_flip_vertically_on_load(true);
    //Model Tree("models/Tree2/tree01.obj");
    ModelAnim Man("models/Man/Mr_Man_Walking.fbx", true);
    Animation ManAnimation("models/Man/Mr_Man_Walking.fbx", &Man);
    Animator animator(&ManAnimation);

    Cube Cube11;
    Cube Cube12;
    Cube Cube13;
    Cube Cube14;
    Cube Cube15;
    Cube Cube21;
    Cube Cube16;
    Cube Cube31;
    Cube Cube41;
    Cube Cube51;
    Cube Cube61;
    Cube Cube71;
    Cube Cube72;
    Cube Cube73;
    Cube Cube74;
    Cube Cube75;
    Cube Cube76;
    
    Cube11.cords = glm::vec3(0.0f, 0.6f, 0.0f);
    Cube12.cords = glm::vec3(1.0f, 0.6f, 1.0f);
    Cube13.cords = glm::vec3(1.0f, 0.6f, 0.0f);
    Cube14.cords = glm::vec3(-1.0f, 0.6f, 0.0f);
    Cube15.cords = glm::vec3(0.0f, 0.6f, 1.0f);
    Cube21.cords = glm::vec3(1.35f, 1.6f, 0.0f);
    Cube16.cords = glm::vec3(5.0f, 0.6f, 2.1f);
    Cube31.cords = glm::vec3(2.35f, 2.6f, 0.0f);
    Cube41.cords = glm::vec3(3.35f, 3.6f, 0.0f);
    Cube51.cords = glm::vec3(4.50f, 4.6f, 0.0f);
    Cube61.cords = glm::vec3(6.0f, 5.6f, 0.0f);
    Cube71.cords = glm::vec3(7.0f, 6.6f, 1.0f);
    Cube72.cords = glm::vec3(7.0f, 6.6f, 0.0f);
    Cube73.cords = glm::vec3(7.0f, 6.6f, -1.0f);
    Cube74.cords = glm::vec3(8.0f, 6.6f, 1.0f);
    Cube76.cords = glm::vec3(8.0f, 6.6f, 0.0f);
    Cube75.cords = glm::vec3(8.0f, 6.6f, -1.0f);

    Cube11.Width = 1.0f;
    Cube12.Width = 1.0f;
    Cube13.Width = 1.0f;
    Cube14.Width = 1.0f;
    Cube15.Width = 1.0f;
    Cube21.Width = 1.0f;
    Cube16.Width = 1.0f;
    Cube31.Width = 1.0f;
    Cube41.Width = 1.0f;
    Cube51.Width = 1.0f;
    Cube61.Width = 1.0f;
    Cube71.Width = 1.0f;
    Cube72.Width = 1.0f;
    Cube73.Width = 1.0f;
    Cube74.Width = 1.0f;
    Cube75.Width = 1.0f;
    Cube76.Width = 1.0f;

    Cube11.Level = 1;
    Cube12.Level = 1;
    Cube13.Level = 1;
    Cube14.Level = 1;
    Cube15.Level = 1;
    Cube21.Level = 2;
    Cube16.Level = 1;
    Cube31.Level = 3;
    Cube41.Level = 4;
    Cube51.Level = 5;
    Cube61.Level = 6;
    Cube71.Level = 7;
    Cube72.Level = 7;
    Cube73.Level = 7;
    Cube74.Level = 7;
    Cube75.Level = 7;
    Cube76.Level = 7;

    // Plane VBO, VAO, EBO
    unsigned int planeVBO, planeVAO, planeEBO;
    glGenVertexArrays(1, &planeVAO);
    glGenBuffers(1, &planeVBO);
    glGenBuffers(1, &planeEBO);

    glBindVertexArray(planeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(PlaneVertices), PlaneVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, planeEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(PlaneIndices), PlaneIndices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // skybox VAO
    unsigned int skyboxVAO, skyboxVBO;
    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    // skybox textures
    std::vector<std::string> faces {
        "cubemap/right.jpg",
        "cubemap/left.jpg",
        "cubemap/top.jpg",
        "cubemap/bottom.jpg",
        "cubemap/front.jpg",
        "cubemap/back.jpg"
    };

    // load cubemap tex
    stbi_set_flip_vertically_on_load(false);
    unsigned int cubemapTexture = loadCubemap(faces);
    stbi_set_flip_vertically_on_load(true);

    // first, configure the cube's VAO (and VBO)
    unsigned int CubeVBO, CubeVAO;
    glGenVertexArrays(1, &CubeVAO);
    glGenBuffers(1, &CubeVBO);

    glBindBuffer(GL_ARRAY_BUFFER, CubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(CubeVertices), CubeVertices, GL_STATIC_DRAW);

    glBindVertexArray(CubeVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, CubeVBO);
    // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // cube tex
    unsigned int CubeTex0 = loadTexture("CubeTexs/container2.png");
    unsigned int CubeTex1 = loadTexture("CubeTexs/bllack.jpeg");
    unsigned int CubeTex2 = loadTexture("CubeTexs/container.jpeg");
    unsigned int CubeTex3 = loadTexture("CubeTexs/PlaneTex.jpeg");
    unsigned int CubeTexBlackSpecular = loadTexture("CubeTexs/blllack.jpeg");
    unsigned int PlaneTex0 = loadTexture("CubeTexs/PlaneTex.jpeg");

    skyboxShader.use();
    skyboxShader.setInt("skybox", 0);

    // shader configuration
    cubeShader.use();
    cubeShader.setInt("material.diffuse", 0);
    cubeShader.setInt("material.specular", 1);
    // Update anim
    animator.UpdateAnimation(0.0f);

    // render loop
    while (!glfwWindowShouldClose(window))
    {

        // per-frame time logic
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        CameraCords = glm::vec3(xWalk, yWalk + 3.4f, zWalk + 4.0f);
        camera.ProcessKeyboardFollow(FOLLOW, deltaTime, CameraCords);

        // Collision detection cords
        LastWalkx = xWalk;
        LastWalky = yWalk;
        LastWalkz = zWalk;

        // should character walk?
        ismoving = false;

        // process Input for movement
        glm::vec2 direction(0.0f, 0.0f);
        direction = ProcessInput(window, direction);

        // Check if Jumped / Needs to rotate? / Is at wall?
        CharRotation(direction);

        //Sort out jumping
        if(jumpLength > 10)
            isjumping = false;
        // Check if now jumping?
        if (isjumping)
        {
            yVelocity = JumpInitVelocity;
        }
        // Apply gravity with Euler integration
        yVelocity += yGravity * deltaTime;

        within1stLevelBoxBounds = false;
        within2ndLevelBoxBounds = false;

        Cube11.CheckCollision(xWalk, yWalk, zWalk);
        Cube12.CheckCollision(xWalk, yWalk, zWalk);
        Cube13.CheckCollision(xWalk, yWalk, zWalk);
        Cube14.CheckCollision(xWalk, yWalk, zWalk);
        Cube15.CheckCollision(xWalk, yWalk, zWalk);
        Cube21.CheckCollision(xWalk, yWalk, zWalk);
        Cube16.CheckCollision(xWalk, yWalk, zWalk);
        Cube31.CheckCollision(xWalk, yWalk, zWalk);
        Cube41.CheckCollision(xWalk, yWalk, zWalk);
        Cube51.CheckCollision(xWalk, yWalk, zWalk);
        Cube61.CheckCollision(xWalk, yWalk, zWalk);
        Cube71.CheckCollision(xWalk, yWalk, zWalk);
        Cube72.CheckCollision(xWalk, yWalk, zWalk);
        Cube73.CheckCollision(xWalk, yWalk, zWalk);
        Cube74.CheckCollision(xWalk, yWalk, zWalk);
        Cube75.CheckCollision(xWalk, yWalk, zWalk);
        Cube76.CheckCollision(xWalk, yWalk, zWalk);

        yWalk += yVelocity * deltaTime;

        // sould do walk anim?
        if(ismoving)
            animator.UpdateAnimation(deltaTime);

        // render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderAnim.use();

        // view and projection
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), 
            (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100000.0f);
        glm::mat4 view = camera.GetViewMatrix();
        shaderAnim.setMat4("projection", projection);
        shaderAnim.setMat4("view", view);

        // Animator + bones
        auto transforms = animator.GetFinalBoneMatrices();
        for (int i = 0; i < transforms.size(); i++)
            shaderAnim.setMat4("finalBonesMatrices[" + std::to_string(i) + "]", transforms[i]);

        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(xWalk, yWalk, zWalk)); 
        model = glm::scale(model, glm::vec3(0.005f, 0.005f, 0.005f));
        model = glm::rotate(model, glm::radians(Rotate), glm::vec3(0.0f, 1.0f, 0.0f));
       
        shaderAnim.setMat4("model", model);
        Man.Draw(shaderAnim);

        /*shader.use();

        // view and projection
        projection = glm::perspective(glm::radians(camera.Zoom), 
            (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100000.0f);
        view = camera.GetViewMatrix();
        shader.setMat4("projection", projection);
        shader.setMat4("view", view);

        model = glm::mat4(1.0f);
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
        model = glm::translate(model, glm::vec3(10.0f, 0.0f, 9.0f)); 

        shader.setMat4("model", model);
        Tree.Draw(shader);*/

        // be sure to activate shader when setting uniforms/drawing objects
        cubeShader.use();
        cubeShader.setVec3("light.position", LightPos);
        cubeShader.setVec3("viewPos", camera.Position);

        // light properties
        cubeShader.setVec3("light.ambient", 0.5f, 0.5f, 0.5f);
        cubeShader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
        cubeShader.setVec3("light.specular", 3.0f, 3.0f, 3.0f);

        // material properties
        cubeShader.setFloat("material.shininess", 5.0f);

        // view/projection transformations
        projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        view = camera.GetViewMatrix();
        cubeShader.setMat4("projection", projection);
        cubeShader.setMat4("view", view);

        // bind diffuse map
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, CubeTex2);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, CubeTex2);

        // Draw cube enviroment
        DrawCube(model, CubePos[0] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[1] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[2] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[3] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[4] ,cubeShader, CubeVAO);

        DrawCube(model, CubePos[5] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[6] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[7] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[8] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[9] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[10] ,cubeShader, CubeVAO);

        DrawCube(model, CubePos[11] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[12] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[13] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[14] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[15] ,cubeShader, CubeVAO);
        DrawCube(model, CubePos[16] ,cubeShader, CubeVAO);

        model = glm::mat4(1.0f);
        cubeShader.setMat4("model", model);

        cubeShader.setVec3("light.specular", 0.05f, 0.05f, 0.05f);


        // bind diffuse map
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, PlaneTex0);
        // bind specular map
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, PlaneTex0);

        glBindVertexArray(planeVAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // also draw the lamp object
        LightShader.use();
        LightShader.setMat4("projection", projection);
        LightShader.setMat4("view", view);
        model = glm::mat4(1.0f);
        model = glm::translate(model, LightPos);
        model = glm::scale(model, glm::vec3(1.0f)); // a smaller cube
        LightShader.setMat4("model", model);

        glBindVertexArray(CubeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // draw skybox as last
        glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
        skyboxShader.use();
        view = glm::mat4(glm::mat3(camera.GetViewMatrix())); // remove translation from the view matrix
        skyboxShader.setMat4("view", view);
        skyboxShader.setMat4("projection", projection);

        // skybox cube
        glBindVertexArray(skyboxVAO);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
        glDepthFunc(GL_LESS); // set depth function back to default

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

// Load texture
unsigned int loadTexture(char const * path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
// loads a cubemap texture from 6 individual texture faces
// order:
// +X (right)
// -X (left)
// +Y (top)
// -Y (bottom)
// +Z (front) 
// -Z (back)
// -------------------------------------------------------
unsigned int loadCubemap(std::vector<std::string> faces)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrComponents;
    
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrComponents, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}
unsigned int loadCubeTexture(const char *path)
{
    //cube tex
    unsigned int Texture;
    glGenTextures(1, &Texture);
    glBindTexture(GL_TEXTURE_2D, Texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    return Texture;
}
void DrawCube(glm::mat4 model, glm::vec3 cords, Shader shader, unsigned int VAO)
{
    model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    model         = glm::translate(model, cords); 
    shader.setMat4("model", model);

    // render box
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}