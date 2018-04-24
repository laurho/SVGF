#ifndef BUFFER_H
#define BUFFER_H

#include "gl/textures/Texture2D.h"

// Base class that captures a lot of the functionality for frame buffers.

class Buffer {
public:
  Buffer(int width, int height);
  ~Buffer();

  void bind() const;
  static void unbind(); // Unbinds whatever current framebuffer is bound
  unsigned int id() const;

protected:
  int m_width, m_height;
  unsigned int m_id;

  // Functions for creating a texture with the given format. The
  // overloads that take only 'type' call RGBAFloatTex or
  // UnsignedByteTex depending on whether type == GL_FLOAT
  CS123::GL::Texture2D makeTexture(GLint internalFormat, GLenum format,
                                   GLenum type, void *data = nullptr);
  CS123::GL::Texture2D makeTexture(GLenum type);
  // Attaches a texture
  void attachTexture(CS123::GL::Texture2D& tex, unsigned int attach_id, bool do_unbind);
  // Creates a texture and attaches it to this framebuffer.
  CS123::GL::Texture2D makeTextureAndAttach(GLint internalFormat, GLenum format,
                                            GLenum type, unsigned int attach_id,
                                            void *data = nullptr, bool do_unbind = false);
  CS123::GL::Texture2D makeTextureAndAttach(GLenum type, unsigned int attach_id,
                                            bool do_unbind = false);
};

#endif // BUFFER_H
