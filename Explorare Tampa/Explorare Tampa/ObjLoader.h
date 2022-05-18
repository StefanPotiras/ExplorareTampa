#pragma once
#include <Gl/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Mesh.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
unsigned int TextureFromFile(const char* path, const string& directory, bool gamma = false);

class ObjLoader
{
public:
    vector<Texture> textures_loaded;
    vector<Mesh> meshes;
    string directory;
    bool gammaCorrection;

    ObjLoader(string const& path, bool gamma = false);
    void Draw(unsigned int shader);
    vector<std::pair<double, double >>vectorColiziune;
    ObjLoader();
private:

    void loadModel(string const& path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);

};

unsigned int TextureFromFile(const char* path, const string& directory, bool gamma);