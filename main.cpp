#include <iostream>
#include <vector>
#include <string>

class System {
public:
    void addArea(const std::string& name, int id) {
        areas.push_back({name, id});
    }

    void updateArea(int id, const std::string& newName) {
        for (auto& area : areas) {
            if (area.id == id) {
                area.name = newName;
                std::cout << "Área atualizada com sucesso.\n";
                return;
            }
        }
        std::cout << "Área não encontrada.\n";
    }

    void deleteArea(int id) {
        for (auto it = areas.begin(); it != areas.end(); ++it) {
            if (it->id == id) {
                areas.erase(it);
                std::cout << "Área excluída com sucesso.\n";
                return;
            }
        }
        std::cout << "Área não encontrada.\n";
    }

    void deleteAllAreas() {
        areas.clear();
        std::cout << "Todas as áreas foram excluídas.\n";
    }

    void listAreas() const {
        if (areas.empty()) {
            std::cout << "Nenhuma área encontrada.\n";
        } else {
            for (const auto& area : areas) {
                std::cout << "Nome: " << area.name << ", ID: " << area.id << '\n';
            }
        }
    }

private:
    struct Area {
        std::string name;
        int id;
    };

    std::vector<Area> areas;
};

int main() {
    System system;
    int opcao;

    do {
        std::cout << "Escolha uma opção:" << std::endl;
        std::cout << "1. Criar área" << std::endl;
        std::cout << "2. Alterar área" << std::endl;
        std::cout << "3. Excluir área" << std::endl;
        std::cout << "4. Consultar áreas" << std::endl;
        std::cout << "5. Sair" << std::endl;

        std::cin >> opcao;

        while (opcao < 1 || opcao > 5) {
            std::cout << "Opção inválida. Tente novamente: ";
            std::cin >> opcao;
        }

        switch (opcao) {
            case 1: {
                int numAreas;
                std::cout << "Adicione o numero de áreas desejado: ";
                std::cin >> numAreas;

                for (int i = 0; i < numAreas; ++i) {
                    std::string areaName;
                    int areaID;
                    std::cout << "Adicione o nome da " << i + 1 << "ª área: ";
                    std::cin >> areaName;
                    std::cout << "Adicione o ID da " << i + 1 << "ª área: ";
                    std::cin >> areaID;
                    system.addArea(areaName, areaID);
                }
                break;
            }

            case 2: {
                int areaID;
                std::string newName;
                std::cout << "Digite o ID da área a ser alterada: ";
                std::cin >> areaID;
                std::cout << "Digite o novo nome da área: ";
                std::cin >> newName;
                system.updateArea(areaID, newName);
                break;
            }

            case 3: {
                int opcaoExcluir;
                std::cout << "Escolha uma opção:" << std::endl;
                std::cout << "1.Excluir uma área" << std::endl;
                std::cout << "2. Excluir todas as áreas"<< std::endl;
                std::cin >> opcaoExcluir;

                if (opcaoExcluir == 1) {
                    int areaID;
                    std::cout << "Digite o ID da área a ser excluída: ";
                    std::cin >> areaID;
                    system.deleteArea(areaID);
                } else if (opcaoExcluir == 2) {
                    system.deleteAllAreas();
                } else {
                    std::cout << "Opção inválida.\n";
                }
                break;
            }

            case 4: {
                system.listAreas();
                break;
            }

            case 5: {
                std::cout << "Saindo do programa"<< std::endl;
                break;
            }

            default:
                std::cout << "Opção inválida.\n";
                break;
        }
    } while (opcao != 5);

    return 0;
}