#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * @brief A estrutura Voxel representa um voxel na grade 3D.
 */
struct Voxel {
  float r; /**< Componentes de cor Vermelho */
  float g; /**< Componentes de cor Verde */
  float b; /**< Componentes de cor Azul */
  float a; /**< Transparência */
  bool show; /**< Variável de apresentação */
};

/**
 * @brief Classe Sculptor
 */
class Sculptor {
private:


  Voxel ***v; // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color

public:

  //Colocar os brefins
  /**
   * @brief Cria a matriz de Voxels, realizando a alocação de memória a partir dos valores dos parâmentros.
   * @param _nx Expessura
   * @param _ny Largura
   * @param _nz Altura
   *
   */
  Sculptor(int _nx, int _ny, int _nz);
  /**
   * @brief Destrutor da classe, Responsável pela liberação da memória alocada.
   *
   *
   *
   */
  ~Sculptor();

  /**
   * @brief Defini a cor atual do desenho e sua trasparência.
   * @param r Vermelho
   * @param g Verde
   * @param b Azul
   * @param a Transparência
   */
  void setColor(float r, float g, float b, float a);
  /**
   * @brief Ativa um voxel nas coordenadas especificadas e atribui a mesma cor do desenho.
   * @param x Coordenada X
   * @param y Coordenada Y
   * @param z Coordenada Z
   */
  void putVoxel(int x, int y, int z);
  /**
   * @brief Escreve a escultura em um arquivo OFF.
   * @param filename Nome do arquivo para ser gerado
   */
  void writeOFF(const char* filename);
  /**
   * @brief Desativa o Voxel nas coordenadas especificadas.
   * @param x Coordenada X
   * @param y Coordenada Y
   * @param z Coordenada Z
   */
  void cutVoxel(int x, int y, int z);
  /**
   * @brief Ativa todos os Voxel nos intervalos fornecidos e atribui a mesma cor do desenho.
   * @param x0 Coordenada x inicial.
   * @param x1 Coordenada x final.
   * @param y0 Coordenada y inicial.
   * @param y1 Coordenada y final.
   * @param z0 Coordenada z inicial.
   * @param z1 Coordenada z final.
   */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief Desativa todos os Voxel nos intervalos fornecidos e atribui a mesma cor do desenho.
   * @param x0 Coordenada x inicial.
   * @param x1 Coordenada x final.
   * @param y0 Coordenada y inicial.
   * @param y1 Coordenada y final.
   * @param z0 Coordenada z inicial.
   * @param z1 Coordenada z final.
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief Ativa todos os Voxels em uma esfera definida pelo centro e raio fornecidos e atribui a cor atual do desenho.
   * @param xcenter Coordenada X do centro da Esfera
   * @param ycenter Coordenada Y do centro da Esfera
   * @param zcenter Coordenada Z do centro da Esfera
   * @param radius  Raio da esfera
   */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief Desativa todos os Voxels em uma esfera definida pelo centro e raio fornecidos e atribui a cor atual do desenho.
   * @param xcenter Coordenada X do centro da Esfera
   * @param ycenter Coordenada Y do centro da Esfera
   * @param zcenter Coordenada Z do centro da Esfera
   * @param radius  Raio da esfera
   */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief Ativa todos os Voxels em um elipsoide definido pelo centro e raios fornecidos.
   * @param xcenter Coordenada X do centro do elipsoide
   * @param ycenter Coordenada Y do centro do elipsoide
   * @param zcenter Coordenada Z do centro do elipsoide
   * @param rx Raio ao longo do eixo X
   * @param ry Raio ao longo do eixo Y
   * @param rz Raio ao longo do eixo Z
   */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief Desativa todos os Voxels em um elipsoide definido pelo centro e raios fornecidos.
   * @param xcenter Coordenada X do centro do elipsoide
   * @param ycenter Coordenada Y do centro do elipsoide
   * @param zcenter Coordenada Z do centro do elipsoide
   * @param rx Raio ao longo do eixo X
   * @param ry Raio ao longo do eixo Y
   * @param rz Raio ao longo do eixo Z
   */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);


};

#endif // SCULPTOR_H
