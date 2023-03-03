#pragma once

#include <string>

namespace Aurora
{
  class Shader
  {
  public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind();
		void Unbind();

		private:
			unsigned int m_RendererID;
	};
}