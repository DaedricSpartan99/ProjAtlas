#ifndef MATERIAL_H
#define MATERIAL_H

struct Material {

    Material(float density, float therm_cond, float elec_cond = 0.0f);
    ~Material();

    float   density,    // K / m**3
            elec_cond,  
            therm_cond;
};

struct SolidMaterial : public Material {

    SolidMaterial(float density, float fus_temp, float therm_cond, float elec_cond = 0.0f);
    ~SolidMaterial();

    float fus_temp; // K
};

struct LiquidMaterial : public Material {

    LiquidMaterial(float density, float fus_temp, float gas_temp, float therm_cond, float elec_cond = 0.0f);
    ~LiquidMaterial();

    float   fus_temp,   // K
            gas_temp;   // K
};

struct GasMaterial : public Material {

    GasMaterial(float density, float gas_temp, float therm_cond, float elec_cond = 0.0f);
    ~GasMaterial();

    float gas_temp; // K
};

#define ICE Material(917.0f, 273.15f, 2.22f)

#endif