#include <GLFW/glfw3.h>
#include <iostream>
#include "InputSystem.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //������������¼�
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
    //������������¼�
    std::cout << "mouse key pressed!" << std::endl;
}

int main()
{
    // ��ʼ�� GLFW
    if (!glfwInit()) {
        return -1;
    }

    // �������ڵ� GLFW ��ʼ������
    GLFWwindow* window = glfwCreateWindow(800, 600, "Engine", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    //���ûص�����
    glfwSetKeyCallback(window, keyCallback);
    //glfwSetCursorPosCallback(window, mouseCallback);

    // ���ô���������
    glfwMakeContextCurrent(window);


    // ��ѭ��
    while (!glfwWindowShouldClose(window)) {
        // ���������¼�����Ⱦ��

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // ������Դ
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}