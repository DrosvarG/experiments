#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <cassert>
#include <iostream>
#include <memory>
#include <print>
#include <utility>

namespace
{
void error_callback(int, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void key_callback(GLFWwindow* window, int key, int /*scancode*/, int action, int /*mods*/)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
}

class GLFWContext
{
public:
    GLFWContext()
    {
        glfwSetErrorCallback(error_callback);
        if(!glfwInit())
            throw std::runtime_error("GLFW Init failed");
    }

    ~GLFWContext()
    {
        glfwTerminate();
    }

    GLFWContext(const GLFWContext&) = delete;
    GLFWContext& operator=(const GLFWContext&) = delete;
    GLFWContext(GLFWContext&&);
    GLFWContext& operator=(GLFWContext&&);
};

struct Size
{
    int width = 0;
    int height = 0;
};

class Window
{
public:
    using window_type = GLFWwindow*;

public:
    Window() = default;
    explicit Window(window_type window) : window_(window) {}
    Window(Window&& other) : window_(std::exchange(other.window_, nullptr)) {}

    Window& operator=(Window&& other)
    {
        if(other == *this)
            return *this;
        window_ = std::exchange(other.window_, nullptr);
        return *this;
    }

    ~Window() { if(valid()) destroy(); }

public:
    static std::optional<window_type> create(const GLFWContext&, Size size, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
    {
        if(auto* window = glfwCreateWindow(size.width, size.height, title, monitor, share))
            return window;
        return std::nullopt;
    }

public:
    GLFWwindow* get() noexcept { return window_; }
    operator window_type() noexcept { return window_; }

    bool valid() const noexcept { return static_cast<bool>(window_); }
    explicit operator bool() const noexcept { return valid(); }

private:
    void destroy()
    {
        assert(window_);
        glfwDestroyWindow(window_);
        window_ = nullptr;
    }

private:
    window_type window_ = nullptr;
};

int main()
{
    try
    {
        GLFWContext context;
        auto window = Window::create(context, Size { 640, 480 }, "Hello World", NULL, NULL);
        if(!window)
        {
            std::println("Failed to created window");
            return 1;
        }

        glfwMakeContextCurrent(window.value());
        glfwSetKeyCallback(window.value(), key_callback);

        while(!glfwWindowShouldClose(window.value()))
        {
            glfwSwapBuffers(window.value());
            glfwPollEvents();
        }
    }
    catch(const std::runtime_error& error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}