struct vec4 {
  union {
    struct {
      float x, y, z, w;
    };
    struct {
      float r, g, b, a;
    };
    struct {
      float s, t, p, q;
    };
    float data[4];
  };

  vec4(float x = 0, float y = 0, float z = 0, float w = 0);

  float& operator[](int i);
  const float& operator[](int i) const;

  vec4 operator+(const vec4& other) const;

  vec4 operator-(const vec4& other) const;

  vec4 operator*(float scalar) const;
};

struct vec3 {
  union {
    struct {
      float x, y, z;
    };
    struct {
      float r, g, b;
    };
    struct {
      float s, t, p;
    };
    float data[3];
  };

  vec3(float x = 0, float y = 0, float z = 0);

  float& operator[](int i);
  const float& operator[](int i) const;

  vec4 operator+(const vec4& other) const;

  vec4 operator-(const vec4& other) const;

  vec4 operator*(float scalar) const;
};

struct vec2 {
  union {
    struct {
      float x, y;
    };
    struct {
      float r, g;
    };
    struct {
      float s, t;
    };
    float data[2];
  };

  vec2(float x = 0, float y = 0, float z = 0);

  float& operator[](int i);
  const float& operator[](int i) const;

  vec4 operator+(const vec4& other) const;
  vec4 operator-(const vec4& other) const;
  vec4 operator*(float scalar) const;
};
