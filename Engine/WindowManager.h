#ifndef VOXEL4_WINDOWMANAGER_H
#define VOXEL4_WINDOWMANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


class WindowManager{
public:
    WindowManager()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        mWindow = glfwCreateWindow(800, 600, "Voxel 4", nullptr, nullptr);
        if (!mWindow)
        {
            std::cout<<"Failed to create GLFW mWindow"<<std::endl;
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(mWindow);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return;
        }
        glViewport(0, 0, 800, 600);
        glfwSetFramebufferSizeCallback(mWindow, framebuffer_size_callback);

    }

    ~WindowManager()
    {
        glfwDestroyWindow(mWindow);
        glfwTerminate();
    }

    GLFWwindow *getWindow() const
    {
        return mWindow;
    }

    void Update()
    {
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }

private:

    GLFWwindow* mWindow;

    static void framebuffer_size_callback(GLFWwindow*, int width, int height)
    {
        glViewport(0, 0, width, height);
    }


};



#endif //VOXEL4_WINDOWMANAGER_H
