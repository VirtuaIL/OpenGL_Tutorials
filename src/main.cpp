#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";




int main()
{


	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Triangle", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);


	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);

	GLfloat vertices[] =
	{ //     COORDINATES     //
		-0.5f, -0.5f, 0.0f, // Lower left corner
		 0.5f, -0.5f, 0.0f, // Lower right corner
		 0.0f,  0.5f, 0.0f  // Upper corner
	};

#pragma region shadery

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

#pragma endregion


#pragma region VAO i VBO

	// KOLEJNOŒÆ:

	// 1. Utworzenie i zbindowanie VAO (Vertex Array Object)

	// 2. Utworzenie i zbindowanie VBO (Vertex Buffer Object)

	// 3. Za³adowanie danych do VBO (Vertex Buffer Object)

	// 4. Konfiguracja czytania atrybutów w VAO (Vertex Array Object)

	// 5. Odbindowanie wszystkiego


	// -------------------------------------------------------


	// VAO - Vertex Array Object
	// VBO - Vertex Buffer Object


	// Tworzenie obiektów: VAO (Vertex Array Object) i VBO (Vertex Buffer Object)
	// VAO zapamiêtuje konfiguracjê atrybutów wierzcho³ków (np. który bufor zawiera dane pozycji, koloru itp.)
	// VBO przechowuje surowe dane wierzcho³ków (pozycje, kolory, tekstury) w pamiêci karty graficznej
	GLuint VAO, VBO;

	// Utworzenie obiektu VAO (reprezentuje "zestaw ustawieñ" do rysowania obiektów)
	glGenVertexArrays(1, &VAO);
	// Aktywacja (zbindowanie) VAO — od tego momentu wszystkie operacje dotycz¹ce VBO i atrybutów
	// bêd¹ zapamiêtane wewn¹trz tego konkretnego VAO
	glBindVertexArray(VAO);


	// Utworzenie bufora VBO, który bêdzie przechowywa³ dane wierzcho³ków
	glGenBuffers(1, &VBO);

	// Zbindowanie bufora VBO do celu GL_ARRAY_BUFFER — oznacza, ¿e operacje na GL_ARRAY_BUFFER
	// (np. wype³nianie danych) bêd¹ dotyczyæ w³aœnie tego bufora
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Przekazanie danych wierzcho³ków do pamiêci karty graficznej
	// sizeof(vertices) – rozmiar ca³ej tablicy danych
	// vertices – wskaŸnik do danych
	// GL_STATIC_DRAW – wskazuje, ¿e dane bêd¹ rzadko zmieniane (optymalizacja sterownika)
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Zdefiniowanie sposobu interpretacji danych w VBO przez potok graficzny:
	// - 0 -> numer atrybutu (location = 0 w shaderze)
	// - 3 -> liczba sk³adowych na wierzcho³ek (x, y, z)
	// - GL_FLOAT -> typ danych
	// - GL_FALSE -> nie normalizuj
	// - 3 * sizeof(float) -> odstêp miêdzy kolejnymi wierzcho³kami (stride)
	// - (void*)0 -> przesuniêcie od pocz¹tku danych (offset = 0)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

	// W³¹czenie u¿ycia atrybutu o indeksie 0 (aktywacja strumienia danych wierzcho³ków)
	glEnableVertexAttribArray(0);

	// Odwi¹zanie bufora VBO (dla porz¹dku; nie jest obowi¹zkowe)
	// Dziêki temu unikamy przypadkowej modyfikacji danych po konfiguracji
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Odwi¹zanie VAO — koñczy konfiguracjê tego zestawu atrybutów
	// Teraz VAO "zapamiêta³o", z jakiego VBO korzysta i jak interpretowaæ dane
	glBindVertexArray(0);

#pragma endregion




	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);



	// Main while loop
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);

		glBindVertexArray(VAO);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);


		// Take care of all GLFW events
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);



	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}