#include "shader.hpp"

GLuint Shader::ReadCompileAndCheckShader(const char* path, const GLuint ID){

    //Read Shader from File
    std::string shaderCode;
    std::ifstream stream(path, std::ios::in);
    if (stream.is_open()){
        std::stringstream sstr;
        sstr << stream.rdbuf();
        shaderCode = sstr.str(); //That's why we love cpp I guess.
        stream.close();
    } else {
        printf("Impossible to open %s. Are you in the right directory ?\n", path);
        getchar();
        return 0;
    }

    //Compile - Pass ID By reference ?[TODO]
    printf("Compiling Shader : %s\n", path);
    char const* sourcePointer = shaderCode.c_str();
    glShaderSource(ID, 1, &sourcePointer, NULL);
    glCompileShader(ID);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    //Check shader
    glGetShaderiv(ID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0){
        std::vector<char> shaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(ID, InfoLogLength, NULL, &shaderErrorMessage[0]);
        printf("%s\n", &shaderErrorMessage[0]);
    }

    return 0;
}

//Loading Shaders
GLuint Shader::LoadShaders(const char * vertex_file_path, const char * fragment_file_path){

    //Create the Shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    //Read Vertex Shader from file
    ReadCompileAndCheckShader(vertex_file_path, VertexShaderID);
    ReadCompileAndCheckShader(fragment_file_path, FragmentShaderID);

    //Link the Program
    printf("Linking Shaders \n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    //Check the program
    GLint Result = GL_FALSE;
    int InfoLogLength;

    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

    //Clear
    glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}
