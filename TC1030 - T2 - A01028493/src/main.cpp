#include <iostream>
#include <string>

using namespace std;

class Envio {
  protected:
   string remitenteNombre;
   string remitenteDireccion;
   string remitenteCiudad;
   string remitenteEstado;
   string remitenteCodigoPostal;
   string destinatarioNombre;
   string destinatarioDireccion;
   string destinatarioCiudad;
   string destinatarioEstado;
   string destinatarioCodigoPostal;
   double costoEnvio;

  public:
   Envio(const string& remitenteNombre, const string& remitenteDireccion,
         const string& remitenteCiudad, const string& remitenteEstado,
         const string& remitenteCodigoPostal, const string& destinatarioNombre,
         const string& destinatarioDireccion, const string& destinatarioCiudad,
         const string& destinatarioEstado,
         const string& destinatarioCodigoPostal, double costoEnvio)
       : remitenteNombre(remitenteNombre),
         remitenteDireccion(remitenteDireccion),
         remitenteCiudad(remitenteCiudad),
         remitenteEstado(remitenteEstado),
         remitenteCodigoPostal(remitenteCodigoPostal),
         destinatarioNombre(destinatarioNombre),
         destinatarioDireccion(destinatarioDireccion),
         destinatarioCiudad(destinatarioCiudad),
         destinatarioEstado(destinatarioEstado),
         destinatarioCodigoPostal(destinatarioCodigoPostal),
         costoEnvio(costoEnvio) {}

   virtual double calculaCosto() { return costoEnvio; }
};

class Paquete : public Envio {
  private:
   double largo;
   double ancho;
   double profundidad;
   double peso;
   double costoPorKg;

  public:
   Paquete(const string& remitenteNombre, const string& remitenteDireccion,
           const string& remitenteCiudad, const string& remitenteEstado,
           const string& remitenteCodigoPostal,
           const string& destinatarioNombre,
           const string& destinatarioDireccion,
           const string& destinatarioCiudad, const string& destinatarioEstado,
           const string& destinatarioCodigoPostal, double costoEnvio,
           double largo, double ancho, double profundidad, double peso,
           double costoPorKg)
       : Envio(remitenteNombre, remitenteDireccion, remitenteCiudad,
               remitenteEstado, remitenteCodigoPostal, destinatarioNombre,
               destinatarioDireccion, destinatarioCiudad, destinatarioEstado,
               destinatarioCodigoPostal, costoEnvio),
         largo(largo),
         ancho(ancho),
         profundidad(profundidad),
         peso(peso),
         costoPorKg(costoPorKg) {}

   double calculaCosto() override {
      double costo = Envio::calculaCosto();
      costo += peso * costoPorKg;
      return costo;
   }
};

class Sobre : public Envio {
  private:
   double largo;
   double ancho;

  public:
   Sobre(const string& remitenteNombre, const string& remitenteDireccion,
         const string& remitenteCiudad, const string& remitenteEstado,
         const string& remitenteCodigoPostal, const string& destinatarioNombre,
         const string& destinatarioDireccion, const string& destinatarioCiudad,
         const string& destinatarioEstado,
         const string& destinatarioCodigoPostal, double costoEnvio,
         double largo, double ancho)
       : Envio(remitenteNombre, remitenteDireccion, remitenteCiudad,
               remitenteEstado, remitenteCodigoPostal, destinatarioNombre,
               destinatarioDireccion, destinatarioCiudad, destinatarioEstado,
               destinatarioCodigoPostal, costoEnvio),
         largo(largo),
         ancho(ancho) {}

   double calculaCosto() override {
      double costo = Envio::calculaCosto();
      if (largo > 25 || ancho > 30) {
         costo += 10;  // Cargos adicionales para dimensiones mayores
      }
      return costo;
   }
};

int main() {
   // Ejemplo de uso
   Envio* envio1 =
       new Paquete("Remitente 1", "Dirección 1", "Ciudad 1", "Estado 1", "CP 1",
                   "Destinatario 1", "Dirección 2", "Ciudad 2", "Estado 2",
                   "CP 2", 10.0, 20.0, 30.0, 10.0, 2.5, 0.5);
   double costoEnvio1 = envio1->calculaCosto();
   cout << "Costo de envío 1: $" << costoEnvio1 << endl;

   Envio* envio2 =
       new Sobre("Remitente 2", "Dirección 3", "Ciudad 3", "Estado 3", "CP 3",
                 "Destinatario 2", "Dirección 4", "Ciudad 4", "Estado 4",
                 "CP 4", 5.0, 30.0, 40.0);
   double costoEnvio2 = envio2->calculaCosto();
   cout << "Costo de envío 2: $" << costoEnvio2 << endl;

   delete envio1;
   delete envio2;

   return 0;
}
