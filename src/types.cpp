
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

  vec4(float x = 0, float y = 0, float z = 0, float w = 0)
  : x(x), y(y), z(z), w(w) {}

  float& operator[](int i) { return data[i]; }
  const float& operator[](int i) const { return data[i]; }

  // Арифметика
  vec4 operator+(const vec4& other) const {
    return vec4(x + other.x, y + other.y, z + other.z, w + other.w);
  }

  vec4 operator-(const vec4& other) const {
    return vec4(x - other.x, y - other.y, z - other.z, w - other.w);
  }

  vec4 operator*(float scalar) const {
    return vec4(x * scalar, y * scalar, z * scalar, w * scalar);
  }
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

  vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

  float& operator[](int i) { return data[i]; }
  const float& operator[](int i) const { return data[i]; }

  // Арифметика
  vec4 operator+(const vec4& other) const {
    return vec4(x + other.x, y + other.y, z + other.z);
  }

  vec4 operator-(const vec4& other) const {
    return vec4(x - other.x, y - other.y, z - other.z);
  }

  vec4 operator*(float scalar) const {
    return vec4(x * scalar, y * scalar, z * scalar);
  }
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

  vec2(float x = 0, float y = 0, float z = 0) : x(x), y(y) {}

  float& operator[](int i) { return data[i]; }
  const float& operator[](int i) const { return data[i]; }

  // Арифметика
  vec4 operator+(const vec4& other) const {
    return vec4(x + other.x, y + other.y);
  }

  vec4 operator-(const vec4& other) const {
    return vec4(x - other.x, y - other.y);
  }

  vec4 operator*(float scalar) const { return vec4(x * scalar, y * scalar); }
};
