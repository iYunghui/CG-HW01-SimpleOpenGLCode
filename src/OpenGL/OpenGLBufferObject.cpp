#include "OpenGLBufferObject.hpp"

#include "OpenGLException.hpp"

#include "Utils/Global.hpp"
#include <iostream>
namespace OpenGL
{

namespace Detail
{

constexpr GLuint noId{0};

bool isCreated(GLuint id) noexcept;

inline bool isCreated(GLuint id) noexcept { return static_cast<bool>(id); }

} // namespace Detail

OpenGLBufferObject::OpenGLBufferObject(
    OpenGLBufferObject::Type type,
    OpenGLBufferObject::UsagePattern usagePattern)
    : id_{Detail::noId}, type_{type}, usagePattern_{usagePattern}
{
    create();
}

OpenGLBufferObject::OpenGLBufferObject(OpenGLBufferObject &&other) noexcept
    : id_{std::move(other.id_)}, type_{std::move(other.type_)},
      usagePattern_{std::move(other.usagePattern_)}
{
    other.id_ = Detail::noId; // Avoid double deletion
}

OpenGLBufferObject &
OpenGLBufferObject::operator=(OpenGLBufferObject &&other) noexcept
{
    if (this != &other)
    {
        if (Detail::isCreated(id_))
        {
            tidy();
        }

        id_ = std::move(other.id_);
        type_ = std::move(other.type_);
        usagePattern_ = std::move(other.usagePattern_);

        other.id_ = Detail::noId; // Avoid double deletion
    }

    return *this;
}

OpenGLBufferObject::~OpenGLBufferObject()
{
    if (Detail::isCreated(id_))
    {
        tidy();
    }
}

void OpenGLBufferObject::allocateBufferData(const void *data,
                                            GLsizeiptr size) noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    // Fill in the Blank
	glBufferData(type_, size, data, usagePattern_);
}

void OpenGLBufferObject::bind() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    // Fill in the Blank
	glBindBuffer(type_, id_);
	
	if(glIsBuffer(id_) == GL_FALSE)
		std::cout<<"is not buffer"<<std::endl;
}

void OpenGLBufferObject::create()
{
    PROGRAM_ASSERT(!Detail::isCreated(id_));

    // Fill in the Blank
	glGenBuffers(1, &id_);

    if (!Detail::isCreated(id_))
    {
        throw OpenGLException("OpenGLBufferObject failed to instantiate.");
    }
}

GLuint OpenGLBufferObject::id() const noexcept { return id_; }

void OpenGLBufferObject::release() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));
	
    // Fill in the Blank
	GLuint temp = 0;
	glBindBuffer(type_, temp);
	glDeleteBuffers(1, &temp);
}

void OpenGLBufferObject::tidy() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    // Fill in the Blank
	// first
	glDeleteBuffers(1, &id_);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
    id_ = Detail::noId;
}

} // namespace OpenGL
