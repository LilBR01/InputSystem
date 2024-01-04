#include <GLFW/glfw3.h>
#include <iostream>
#include "InputSystem.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //处理键盘输入事件
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
    {
        std::cout << "E key pressed!" << std::endl;
    }
}

void keyTest()
{

}

void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
    //处理鼠标输入事件
    std::cout << "mouse key pressed!" << std::endl;
}

int main()
{
    // 初始化 GLFW
    if (!glfwInit()) {
        return -1;
    }

    // 创建窗口等 GLFW 初始化工作
    GLFWwindow* window = glfwCreateWindow(800, 600, "Engine", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    //设置回调函数
    glfwSetKeyCallback(window, keyCallback);
    //glfwSetCursorPosCallback(window, mouseCallback);

    // 设置窗口上下文
    glfwMakeContextCurrent(window);


    // 主循环
    while (!glfwWindowShouldClose(window)) {
        // 处理输入事件、渲染等

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 清理资源
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}