#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Model.hpp"
#include "Shader.hpp"
#include "Buffers.hpp"
#include "Window.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "Terrain.hpp"
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
#include "Timer.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <ft2build.h>
#include "Text.hpp"
#include FT_FREETYPE_H  

#include "Texture.hpp"

bool visioned = false;

//#include "Engine.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void processInput(GLFWwindow* window, double delta);


// camera
glm::vec3 cameraPos = glm::vec3(2.0f, 1.0f, 2.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

bool firstMouse = true;
float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch = 0.0f;
float lastX = 1200.0f / 2.0;
float lastY = 900.0 / 2.0;
float fov = 45.0f;


int taber = 0;

int main()
{

    

  Window window;
  
  //-------------------------------------------
  Model model1[293];
  Terrain terrainl[809];

  //-----------------------------------------

  Model model2[293];
  Terrain terrain2[893];

  //-----------------------------------------
	
  glEnable(GL_DEPTH_TEST);
  //glEnable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  //-------------------------------------------------------------------------------------------------------------------------
  Shader ourShader("vertex.glsl", "fragment.glsl"/*,"geometry.glsl"*/); // you can name your shader files however you like
  //-------------------------------------------------------------------------------------------------------------------------
  Shader ourShader1("vertex1.glsl", "fragment1.glsl"/*,"geometry.glsl"*/); // you can name your shader files however you like
  //-------------------------------------------------------------------------------------------------------------------------
  Shader ourShader2("vertex2.glsl", "fragment2.glsl"/*,"geometry.glsl"*/); // you can name your shader files however you like
  //-------------------------------------------------------------------------------------------------------------------------
  Shader ourShader3("vertex3.glsl", "fragment3.glsl");
  //-------------------------------------------------------------------------------------------------------------------------
  //model1.indices.size();
  //cubepos.

  // auto &itterrainverices = *terrainl.vertices.begin();
  // auto &itterrainindices = *terrainl.indices.begin();
  //---------------------------------------------------------------------------------------------------
  VAO vao;
  vao.Bind();
  VBO vbo(&terrainl[0].vertices[0], terrainl[0].vertices.size() * sizeof(terrainl[0].vertices));
  vbo.Bind();
  EBO ebo(&terrainl[0].indices[0], terrainl[0].indices.size() * sizeof(terrainl[0].indices));
  ebo.Bind();
  vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
  vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  vao.Unbind();
  vbo.Unbind();

  VAO vao1;
  vao1.Bind();
  VBO vbo1(&model1[0].vertices[0], model1[0].vertices.size() * sizeof(model1[0].vertices));
  vbo1.Bind();
  EBO ebo1(&model1[0].indices[0], model1[0].indices.size() * sizeof(model1[0].indices));
  ebo1.Bind();
  vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
  vao1.LinkAttrib(vbo1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  vao1.LinkAttrib(vbo1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  vao1.Unbind();
  vbo1.Unbind();
  //----------------------------------------------------------------------------------------------------
  VAO vao2;
  vao2.Bind();
  VBO vbo2(&terrain2[0].vertices[0], terrain2[0].vertices.size() * sizeof(terrain2[0].vertices));
  vbo2.Bind();
  EBO ebo2(&terrain2[0].indices[0], terrain2[0].indices.size() * sizeof(terrain2[0].indices));
  ebo2.Bind();
  vao2.LinkAttrib(vbo2, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
  vao2.LinkAttrib(vbo2, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  vao2.LinkAttrib(vbo2, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  vao2.Unbind();
  vbo2.Unbind();

  VAO vao3;
  vao3.Bind();
  VBO vbo3(&model2[0].vertices[0], model2[0].vertices.size() * sizeof(model2[0].vertices));
  vbo3.Bind();
  EBO ebo3(&model2[0].indices[0], model2[0].indices.size() * sizeof(model2[0].indices));
  ebo3.Bind();
  vao3.LinkAttrib(vbo3, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
  vao3.LinkAttrib(vbo3, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  vao3.LinkAttrib(vbo3, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  vao3.Unbind();
  vbo3.Unbind();
  //-----------------------------------------------------------------------------------------------------
	
  Texture* texture1 = load_texture("img1.png");
  if (!texture1) {
	std::cerr << "Error TEXTURE LOAD" << std::endl;
	//delete shader;
	window.clean();
	return 1;
  }
  //-------------------------------------------------------
  	
  Texture* texture = load_texture("img1.png");
  if (!texture) {
	std::cerr << "Error TEXTURE LOAD" << std::endl;
	//delete shader;
	window.clean();
	return 1;
  }




  
  ourShader.use();
  ourShader.setInt("texture1", 0);
  //-------------------------------------------------------
  ourShader1.use();
  ourShader1.setInt("texture1", 0);
  //-------------------------------------------------------
  ourShader2.use();
  ourShader2.setInt("texture1", 0);
  //-------------------------------------------------------
  ourShader3.use();
  ourShader3.setInt("texture1", 0);
  //-------------------------------------------------------
	
	
  Text* text = new Text();

  Timer timer;
  glfwSetInputMode(window.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  //glfwSetFramebufferSizeCallback(window.window, framebuffer_size_callback);
  glfwSetCursorPosCallback(window.window, mouse_callback);


	
  //-------------------------------------------------------------------------
	
  glm::vec3 cubes[293] = {
	/*glm::vec3(-4.0f, 0.01f, -4.0f),
	  glm::vec3(-4.0f, 0.01f, 4.0f),
	  glm::vec3(4.0f, 0.01f, 4.0f),
	  glm::vec3(4.0f, 0.01f, -4.0f)*/
  };

  glm::vec3 cubepos[809] = {
	/*glm::vec3(0.0f, 0.0f, 0.0f),
	  glm::vec3(0.0f, 0.0f, -2.0f),
	  glm::vec3(-2.0f, 0.0f, -2.0f),
	  glm::vec3(-2.0f, 0.0f, 0.0f),
	  glm::vec3(-2.0f, 0.0f, 2.0f),
	  glm::vec3(0.0f, 0.0f, 2.0f),
	  glm::vec3(2.0f, 0.0f, 2.0f),
	  glm::vec3(2.0f, 0.0f, 0.0f),
	  glm::vec3(2.0f, 0.0f, -2.0f),
	  glm::vec3(0.0f, 0.0f, -4.0f),
	  glm::vec3(-4.0f, 0.0f, -4.0f),
	  glm::vec3(-4.0f, 0.0f, 0.0f),
	  glm::vec3(-4.0f, 0.0f, 4.0f),
	  glm::vec3(0.0f, 0.0f, 4.0f),
	  glm::vec3(4.0f, 0.0f, 4.0f),
	  glm::vec3(4.0f, 0.0f, 0.0f),
	  glm::vec3(4.0f, 0.0f, -4.0f),*/
        
  };
  //---------------------------------------------------------------------------
  std::fstream is;

  is.open("1.txt", std::fstream::in | std::fstream::out);
    
  if(!is.is_open())
	{
	  window.clean();
	}
	
  char cho1;

   
  int hu = 0, wu = 0, countu = 0, count = 0;

  while (is.get(cho1)) {
	if (cho1 == '#') {
	  std::cout << "#";
	  //block++;
	  cubes[count]={ glm::vec3(wu, 0.1f, hu) };
	  wu += 2;
	  count++;
	}
	else if (cho1 == '.') {
	  std::cout << ".";
	  //places++;
	  cubepos[countu] = { glm::vec3(wu, 0.1f, hu) };
	  wu += 2;
	  countu++;
	}
	else if (cho1 == '\n') {
	  std::cout << "\n";
	  hu += 2;
	  //hu++;
	  wu = 0;
	  //countu++;
	  //count++;
	}
  }
  // }
  std::cout << "\n";
  // }
  std::cout<<"DownloadFIleComplete{1}\n"<<count<<"\n"<<countu<<"\n"<<wu<<"\n"<<hu<<"\n";
  is.close();
  //-----------------------------------------------------------------------------------------     



	
	
  //-------------------------------------------------------------------------
	
  glm::vec3 cubes1[293] = {
	/*glm::vec3(-4.0f, 0.01f, -4.0f),
	  glm::vec3(-4.0f, 0.01f, 4.0f),
	  glm::vec3(4.0f, 0.01f, 4.0f),
	  glm::vec3(4.0f, 0.01f, -4.0f)*/
  };

  glm::vec3 cubepos1[809] = {
	/*glm::vec3(0.0f, 0.0f, 0.0f),
	  glm::vec3(0.0f, 0.0f, -2.0f),
	  glm::vec3(-2.0f, 0.0f, -2.0f),
	  glm::vec3(-2.0f, 0.0f, 0.0f),
	  glm::vec3(-2.0f, 0.0f, 2.0f),
	  glm::vec3(0.0f, 0.0f, 2.0f),
	  glm::vec3(2.0f, 0.0f, 2.0f),
	  glm::vec3(2.0f, 0.0f, 0.0f),
	  glm::vec3(2.0f, 0.0f, -2.0f),
	  glm::vec3(0.0f, 0.0f, -4.0f),
	  glm::vec3(-4.0f, 0.0f, -4.0f),
	  glm::vec3(-4.0f, 0.0f, 0.0f),
	  glm::vec3(-4.0f, 0.0f, 4.0f),
	  glm::vec3(0.0f, 0.0f, 4.0f),
	  glm::vec3(4.0f, 0.0f, 4.0f),
	  glm::vec3(4.0f, 0.0f, 0.0f),
	  glm::vec3(4.0f, 0.0f, -4.0f),*/
        
  };
  //---------------------------------------------------------------------------
  std::fstream is1;

  is1.open("2.txt", std::fstream::in | std::fstream::out);
    
  if(!is1.is_open())
	{
	  window.clean();
	}
	
  char cho2;

   
  int hu1 = 0, wu1 = 110, countu1 = 0, count1 = 0;

  while (is1.get(cho2)) {
	if (cho2 == '#') {
	  std::cout << "#";
	  //block++;
	  cubes1[count1]={ glm::vec3(wu1, 0.1f, hu1) };
	  wu1 += 2;
	  count1++;
	}
	else if (cho2 == '.') {
	  std::cout << ".";
	  //places++;
	  cubepos1[countu1] = { glm::vec3(wu1, 0.1f, hu1) };
	  wu1 += 2;
	  countu1++;
	}
	else if (cho2 == '\n') {
	  std::cout << "\n";
	  hu1 += 2;
	  //hu++;
	  wu1 = 110;
	  //countu++;
	  //count++;
	}
  }
  // }
  std::cout << "\n";
  // }
  std::cout<<"DownloadFIleComplete{2}\n"<<count1<<"\n"<<countu1<<"\n"<<wu1<<"\n"<<hu1<<"\n";
  is1.close();
  //-----------------------------------------------------------------------------------------     



  // std::cout << "OpenGL version: " << glGetString(GL_VERSION) << " bytes" << std::endl;
  // std::cout << "Max Geometry Uniform Blocks: " << GL_MAX_GEOMETRY_UNIFORM_BLOCKS << " bytes" << std::endl;
  // std::cout << "Max Geometry Shader Invocations: " << GL_MAX_GEOMETRY_SHADER_INVOCATIONS << " bytes" << std::endl;
  //std::cout << "Max Uniform Buffer Bindings: " << GL_MAX_UNIFORM_BUFFER_BINDINGS << " bytes" << std::endl;
  //std::cout << "Max Uniform Block Size: " << GL_MAX_UNIFORM_BLOCK_SIZE << " bytes" << std::endl;
  //std::cout << "Max SSBO Block Size: " << GL_MAX_SHADER_STORAGE_BLOCK_SIZE << " bytes" << std::endl;
    
    

  while (!glfwWindowShouldClose(window.window))
    {
	  timer.startingTime();
        
	  processInput(window.window,timer.delta);

	  
        

        

       
	  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      //glViewport(1,1,1200/4,800/4);
	  glViewport(0, 0, 1200, 900);
	  //glActiveTexture(GL_TEXTURE0);
	  glBindTexture(GL_TEXTURE_2D, texture1->id);
       
	  ourShader.use();

        

	  ourShader1.use();
	  ourShader2.use();
	  ourShader3.use();

	  // camera/view transformation
	  glm::mat4 projection = glm::perspective(glm::radians(fov), (float)1200 / (float)900, 0.1f, 100.0f);
	  ourShader.setMat4("projection", projection);
	  ourShader1.setMat4("projection", projection);
	  ourShader2.setMat4("projection",projection);
	  ourShader3.setMat4("projection",projection);
	  // camera/view transformation
	  //pitch =+90;
	  glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	  ourShader.setMat4("view", view);
	  ourShader1.setMat4("view", view);
	  ourShader2.setMat4("view", view);
	  ourShader3.setMat4("view", view);

	  //glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	  //model = glm::translate(model, cubepos[0]);
	  //glm::mat4 model1 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	  //model = glm::translate(model, cubepos[1]);
	  //float angle = 20.0f * glfwGetTime()* glm::sin(1);
	  //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
	  vao.Bind();
        
	  for (int i = 0; i < countu; i++)
        {
		  // calculate the model matrix for each object and pass it to shader before drawing
		  glm::mat4 model = glm::mat4(1.0f);
		  model = glm::translate(model, cubepos[i]);
		  //cubepos[i].y=cubepos[i].y* glfwGetTime();
            
		  //glm::mat4 model12 = glm::mat4(1.0f);
		  //model = glm::translate(model12, cubes[i]);

		  //float angle = 20.0f * i;
		  //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		  ourShader.setMat4("model", model);

		  //ourShader.setMat4("model", model12);

		  glDrawElements(GL_TRIANGLES, terrainl[i].indices.size(), GL_UNSIGNED_INT, 0);

		  //glDrawElements(GL_TRIANGLES, model1[i].indices.size(), GL_UNSIGNED_INT, 0);
            
            
        }
	  //cubepos[0].z -= glm::sin(0.0005f);
	  //ourShader.setMat4("model", model);
	  //vao1.Bind();
	  vao1.Bind();
	  //ourShader1.setVec3("skyColor", 0.1f, 0.1f, 0.1f);
	  for (int i = 0; i < count; i++)
        {
		  // calculate the model matrix for each object and pass it to shader before drawing
		  glm::mat4 model12 = glm::mat4(1.0f);
		  model12 = glm::translate(model12, cubes[i]);
		  //float angle = 20.0f * i;
		  //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		  ourShader1.setMat4("model", model12);

		  glDrawElements(GL_TRIANGLES, model1[i].indices.size(), GL_UNSIGNED_INT, 0);


        }


	  if (cameraPos.y != 1) {
		cameraPos.y = 1;
	  }


	  if(cameraPos.x ==24 && cameraPos.z < 24 || cameraPos.z >22 )
		{
		  //	if(visioned == false)
		  //{
		  //	visioned = true;
				
		  //				ourShader2.use();
		  //ourShader3.use();

		  //				ourShader2.setMat4("projection", projection);
		  //ourShader3.setMat4("projection", projection);
				
		  //ourShader2.setMat4("view", view);
		  //ourShader3.setMat4("view", view);

		  vao2.Bind();
		  //vao3.Bind();


		  for (int i = 0; i < countu1; i++)
			{
			  // calculate the model matrix for each object and pass it to shader before drawing
			  glm::mat4 model2 = glm::mat4(1.0f);
			  model2 = glm::translate(model2, cubepos1[i]);
			  //cubepos[i].y=cubepos[i].y* glfwGetTime();
            
			  //glm::mat4 model12 = glm::mat4(1.0f);
			  //model = glm::translate(model12, cubes[i]);

			  //float angle = 20.0f * i;
			  //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			  ourShader2.setMat4("model", model2);

			  //ourShader.setMat4("model", model12);

			  glDrawElements(GL_TRIANGLES, terrain2[i].indices.size(), GL_UNSIGNED_INT, 0);

			  //glDrawElements(GL_TRIANGLES, model1[i].indices.size(), GL_UNSIGNED_INT, 0);
            
            
			}
		  //cubepos[0].z -= glm::sin(0.0005f);
		  //ourShader.setMat4("model", model);
		  //vao1.Bind();
		  //vao1.Bind();
		  //ourShader1.setVec3("skyColor", 0.1f, 0.1f, 0.1f);
		  vao3.Bind();
		  for (int i = 0; i < count1; i++)
			{
			  // calculate the model matrix for each object and pass it to shader before drawing
			  glm::mat4 model13 = glm::mat4(1.0f);
			  model13 = glm::translate(model13, cubes1[i]);
			  //float angle = 20.0f * i;
			  //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			  ourShader3.setMat4("model", model13);

			  glDrawElements(GL_TRIANGLES, model2[i].indices.size(), GL_UNSIGNED_INT, 0);


			}

				
				
		  //			  }
		  //	if(visioned == true)
		  //	  {
		  //		continue;
		  //	  }
			
			
			
		         	


			
		}

        

	  /*if (cameraPos.x < -5 || cameraPos.z<-5 || cameraPos.x > 5 || cameraPos.z > 5) {
		cameraPos.y *= (-0.2) * glfwGetTime();
		}*/
	  // if (cameraPos.x > -2 || cameraPos.z < 2 || cameraPos.x < 2 || cameraPos.z > -2) {
	  //    //for (int i = 0; i < 4; i++) {
	  //        terrainl[0].vertices.clear();
	  //        terrainl[0].indices.clear();
	  //        terrainl[0].init(2.5f);
	  //        vao.Unbind();
	  //        vbo.Unbind();
	  //        vao.Bind();
	  //        VBO vbo(&terrainl[0].vertices[0], terrainl[0].vertices.size() * sizeof(terrainl[0].vertices));
	  //        vbo.Bind();
	  //        EBO ebo(&terrainl[0].indices[0], terrainl[0].indices.size() * sizeof(terrainl[0].indices));
	  //        ebo.Bind();
	  //        vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	  //        vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	  //        vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	  //        vao.Unbind();
	  //        vbo.Unbind();
	  //    //}
	  //}
        
            



	  if (glfwGetKey(window.window, GLFW_KEY_1) == GLFW_PRESS) {
		// model1.vertices.clear();
		// model1.indices.clear();
		// model1.init(20.0f);
		//  vao.Unbind();
		// vbo.Unbind();
		//  vao.Bind();
		// VBO vbo(&model1.vertices[0], model1.vertices.size() * sizeof(model1.vertices));
		// vbo.Bind();
		// EBO ebo(&model1.indices[0], model1.indices.size() * sizeof(model1.indices));
		// ebo.Bind();
		// vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		//vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		//  vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		//  vao.Unbind();
		//  vbo.Unbind();
	  }
	  if (glfwGetKey(window.window, GLFW_KEY_2) == GLFW_PRESS) {
		//model1.vertices.clear();
		//model1.indices.clear();
		//model1.init(10.0f);
		//vao.Unbind();
		//vbo.Unbind();
		//vao.Bind();
		//VBO vbo(&model1.vertices[0], model1.vertices.size() * sizeof(model1.vertices));
		//vbo.Bind();
		//EBO ebo(&model1.indices[0], model1.indices.size() * sizeof(model1.indices));
		//ebo.Bind();
		//vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		////vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		//vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		//vao.Unbind();
		//vbo.Unbind();
	  }
	  if (glfwGetKey(window.window, GLFW_KEY_3) == GLFW_PRESS) {
		//model1.vertices.clear();
		//model1.indices.clear();
		//model1.init(5.0f);
		//vao.Unbind();
		//vbo.Unbind();
		//vao.Bind();
		//VBO vbo(&model1.vertices[0], model1.vertices.size() * sizeof(model1.vertices));
		//vbo.Bind();
		//EBO ebo(&model1.indices[0], model1.indices.size() * sizeof(model1.indices));
		//ebo.Bind();
		//vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		////vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		//vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		//vao.Unbind();
		//vbo.Unbind();
	  }
	  if (glfwGetKey(window.window, GLFW_KEY_4) == GLFW_PRESS) {
		for (int i = 0; i < count; i++) {
		  model1[i].vertices.clear();
		  model1[i].indices.clear();
		  model1[i].init(2.5f);
		  vao1.Unbind();
		  vbo1.Unbind();
		  vao1.Bind();
		  VBO vbo1(&model1[i].vertices[0], model1[i].vertices.size() * sizeof(model1[i].vertices));
		  vbo1.Bind();
		  EBO ebo1(&model1[i].indices[0], model1[i].indices.size() * sizeof(model1[i].indices));
		  ebo1.Bind();
		  vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		  //vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		  vao1.LinkAttrib(vbo1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		  vao1.Unbind();
		  vbo1.Unbind();
		}
	  }

	  //if()



		
	  //for(int i=0;i<9;i++)
         
	  // 
	  //glDrawArrays(GL_TRIANGLES, 0, model1.indices.size());


	  text->RenderText("Press 1 2 3 4", 100.0f, 25.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
	  text->RenderText("(C) LearnOpenGL.com", 900.0f, 870.0f, 0.4f, glm::vec3(0.3, 0.7f, 0.9f));
      //glClearColor(0,0,0,1.0);

	  //glfwSwapBuffers(window.window);
	  //glClearColor(0.0f,0.0f,0.0f,1.0f);
      //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_BLEND_COLOR);
	  //gluOrtho2D(0,1200/4 ,800/4 ,0 );
	  glViewport(900, 700, 1200/4, 900/4);

	  


	  glBindTexture(GL_TEXTURE_2D, texture->id);
       
	  ourShader.use();

        

	  ourShader1.use();
	  ourShader2.use();
	  ourShader3.use();

	  // camera/view transformation
	  glm::mat4 projection1 = glm::perspective(glm::radians(fov), (float)1200 / (float)900, 0.1f, 100.0f);
	  ourShader.setMat4("projection", projection1);
	  ourShader1.setMat4("projection", projection1);
	  ourShader2.setMat4("projection",projection1);
	  ourShader3.setMat4("projection",projection1);
	  // camera/view transformation
	  pitch = -90.0f;
	  glm::mat4 view1 = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	  ourShader.setMat4("view", view1);
	  ourShader1.setMat4("view", view1);
	  ourShader2.setMat4("view", view1);
	  ourShader3.setMat4("view", view1);

	  //glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	  //model = glm::translate(model, cubepos[0]);
	  //glm::mat4 model1 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	  //model = glm::translate(model, cubepos[1]);
	  //float angle = 20.0f * glfwGetTime()* glm::sin(1);
	  //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
	  vao.Bind();
        
	  for (int i = 0; i < countu; i++)
        {
		  // calculate the model matrix for each object and pass it to shader before drawing
		  glm::mat4 model = glm::mat4(1.0f);
		  model = glm::translate(model, cubepos[i]);
		  //cubepos[i].y=cubepos[i].y* glfwGetTime();
            
		  //glm::mat4 model12 = glm::mat4(1.0f);
		  //model = glm::translate(model12, cubes[i]);

		  //float angle = 20.0f * i;
		  //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		  ourShader.setMat4("model", model);

		  //ourShader.setMat4("model", model12);

		  glDrawElements(GL_TRIANGLES, terrainl[i].indices.size(), GL_UNSIGNED_INT, 0);

		  //glDrawElements(GL_TRIANGLES, model1[i].indices.size(), GL_UNSIGNED_INT, 0);
            
            
        }
	  //cubepos[0].z -= glm::sin(0.0005f);
	  //ourShader.setMat4("model", model);
	  //vao1.Bind();
	  vao1.Bind();
	  //ourShader1.setVec3("skyColor", 0.1f, 0.1f, 0.1f);
	  for (int i = 0; i < count; i++)
        {
		  // calculate the model matrix for each object and pass it to shader before drawing
		  glm::mat4 model12 = glm::mat4(1.0f);
		  model12 = glm::translate(model12, cubes[i]);
		  //float angle = 20.0f * i;
		  //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		  ourShader1.setMat4("model", model12);

		  glDrawElements(GL_TRIANGLES, model1[i].indices.size(), GL_UNSIGNED_INT, 0);


        }


	  if (cameraPos.y != 1) {
		cameraPos.y = 1;
	  }


	  if(cameraPos.x ==24 && cameraPos.z < 24 || cameraPos.z >22 )
		{
		  //	if(visioned == false)
		  //{
		  //	visioned = true;
				
		  //				ourShader2.use();
		  //ourShader3.use();

		  //				ourShader2.setMat4("projection", projection);
		  //ourShader3.setMat4("projection", projection);
				
		  //ourShader2.setMat4("view", view);
		  //ourShader3.setMat4("view", view);

		  vao2.Bind();
		  //vao3.Bind();


		  for (int i = 0; i < countu1; i++)
			{
			  // calculate the model matrix for each object and pass it to shader before drawing
			  glm::mat4 model2 = glm::mat4(1.0f);
			  model2 = glm::translate(model2, cubepos1[i]);
			  //cubepos[i].y=cubepos[i].y* glfwGetTime();
            
			  //glm::mat4 model12 = glm::mat4(1.0f);
			  //model = glm::translate(model12, cubes[i]);

			  //float angle = 20.0f * i;
			  //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			  ourShader2.setMat4("model", model2);

			  //ourShader.setMat4("model", model12);

			  glDrawElements(GL_TRIANGLES, terrain2[i].indices.size(), GL_UNSIGNED_INT, 0);

			  //glDrawElements(GL_TRIANGLES, model1[i].indices.size(), GL_UNSIGNED_INT, 0);
            
            
			}
		  //cubepos[0].z -= glm::sin(0.0005f);
		  //ourShader.setMat4("model", model);
		  //vao1.Bind();
		  //vao1.Bind();
		  //ourShader1.setVec3("skyColor", 0.1f, 0.1f, 0.1f);
		  vao3.Bind();
		  for (int i = 0; i < count1; i++)
			{
			  // calculate the model matrix for each object and pass it to shader before drawing
			  glm::mat4 model13 = glm::mat4(1.0f);
			  model13 = glm::translate(model13, cubes1[i]);
			  //float angle = 20.0f * i;
			  //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			  ourShader3.setMat4("model", model13);

			  glDrawElements(GL_TRIANGLES, model2[i].indices.size(), GL_UNSIGNED_INT, 0);


			}

				
				
		  //			  }
		  //	if(visioned == true)
		  //	  {
		  //		continue;
		  //	  }
			
			
			
		         	


			
		}

        

	  /*if (cameraPos.x < -5 || cameraPos.z<-5 || cameraPos.x > 5 || cameraPos.z > 5) {
		cameraPos.y *= (-0.2) * glfwGetTime();
		}*/
	  // if (cameraPos.x > -2 || cameraPos.z < 2 || cameraPos.x < 2 || cameraPos.z > -2) {
	  //    //for (int i = 0; i < 4; i++) {
	  //        terrainl[0].vertices.clear();
	  //        terrainl[0].indices.clear();
	  //        terrainl[0].init(2.5f);
	  //        vao.Unbind();
	  //        vbo.Unbind();
	  //        vao.Bind();
	  //        VBO vbo(&terrainl[0].vertices[0], terrainl[0].vertices.size() * sizeof(terrainl[0].vertices));
	  //        vbo.Bind();
	  //        EBO ebo(&terrainl[0].indices[0], terrainl[0].indices.size() * sizeof(terrainl[0].indices));
	  //        ebo.Bind();
	  //        vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	  //        vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	  //        vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	  //        vao.Unbind();
	  //        vbo.Unbind();
	  //    //}
	  //}
        
            



	  if (glfwGetKey(window.window, GLFW_KEY_1) == GLFW_PRESS) {
		// model1.vertices.clear();
		// model1.indices.clear();
		// model1.init(20.0f);
		//  vao.Unbind();
		// vbo.Unbind();
		//  vao.Bind();
		// VBO vbo(&model1.vertices[0], model1.vertices.size() * sizeof(model1.vertices));
		// vbo.Bind();
		// EBO ebo(&model1.indices[0], model1.indices.size() * sizeof(model1.indices));
		// ebo.Bind();
		// vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		//vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		//  vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		//  vao.Unbind();
		//  vbo.Unbind();
	  }
	  if (glfwGetKey(window.window, GLFW_KEY_2) == GLFW_PRESS) {
		//model1.vertices.clear();
		//model1.indices.clear();
		//model1.init(10.0f);
		//vao.Unbind();
		//vbo.Unbind();
		//vao.Bind();
		//VBO vbo(&model1.vertices[0], model1.vertices.size() * sizeof(model1.vertices));
		//vbo.Bind();
		//EBO ebo(&model1.indices[0], model1.indices.size() * sizeof(model1.indices));
		//ebo.Bind();
		//vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		////vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		//vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		//vao.Unbind();
		//vbo.Unbind();
	  }
	  if (glfwGetKey(window.window, GLFW_KEY_3) == GLFW_PRESS) {
		//model1.vertices.clear();
		//model1.indices.clear();
		//model1.init(5.0f);
		//vao.Unbind();
		//vbo.Unbind();
		//vao.Bind();
		//VBO vbo(&model1.vertices[0], model1.vertices.size() * sizeof(model1.vertices));
		//vbo.Bind();
		//EBO ebo(&model1.indices[0], model1.indices.size() * sizeof(model1.indices));
		//ebo.Bind();
		//vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		////vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		//vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		//vao.Unbind();
		//vbo.Unbind();
	  }
	  if (glfwGetKey(window.window, GLFW_KEY_4) == GLFW_PRESS) {
		for (int i = 0; i < count; i++) {
		  model1[i].vertices.clear();
		  model1[i].indices.clear();
		  model1[i].init(2.5f);
		  vao1.Unbind();
		  vbo1.Unbind();
		  vao1.Bind();
		  VBO vbo1(&model1[i].vertices[0], model1[i].vertices.size() * sizeof(model1[i].vertices));
		  vbo1.Bind();
		  EBO ebo1(&model1[i].indices[0], model1[i].indices.size() * sizeof(model1[i].indices));
		  ebo1.Bind();
		  vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		  //vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		  vao1.LinkAttrib(vbo1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		  vao1.Unbind();
		  vbo1.Unbind();
		}
	  }

	  //if()



		
	  //for(int i=0;i<9;i++)
         
	  // 
	  //glDrawArrays(GL_TRIANGLES, 0, model1.indices.size());


	  text->RenderText("Press 1 2 3 4", 100.0f, 25.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
	  text->RenderText("(C) LearnOpenGL.com", 900.0f, 870.0f, 0.4f, glm::vec3(0.3, 0.7f, 0.9f));
      //glClearColor(0,0,0,1.0);







	  
	  
	  glfwSwapBuffers(window.window);
	  glfwPollEvents();
    }

    
  vao.Delete();
  vbo.Delete();
  vao1.Delete();
  vbo1.Delete();

  
  vao2.Delete();
  vao3.Delete();
  vbo2.Delete();
  vbo3.Delete();
  ebo2.Delete();
  ebo3.Delete();

  
  //model1.clean();
  delete text;
  ebo.Delete();
  ebo1.Delete();
  window.clean();
  return 0;
}

void processInput(GLFWwindow* window,double delta)
{
    
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	glfwSetWindowShouldClose(window, true);
  if (glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS)
    {   
	  taber += 1;
	  if (taber == 1) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	  }
	  if(taber==2) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		taber = 0;
	  }
    }
  float cameraSpeed = 0.1;
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	cameraPos += cameraSpeed * cameraFront;
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	cameraPos -= cameraSpeed * cameraFront;
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
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

  float sensitivity = 0.1f; // change this value to your liking
  xoffset *= sensitivity;
  yoffset *= sensitivity;

  yaw += xoffset;
  pitch += yoffset;

  // make sure that when pitch is out of bounds, screen doesn't get flipped
  if (pitch > 89.0f)
	pitch = 89.0f;
  if (pitch < -89.0f)
	pitch = -89.0f;

  glm::vec3 front;
  front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  front.y = sin(glm::radians(pitch));
  front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  cameraFront = glm::normalize(front);
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

  glViewport(0, 0, width, height);
}
