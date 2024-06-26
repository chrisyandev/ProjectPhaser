#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Core.h"

namespace ph
{
    class AssetManager
    {
    public:
        static AssetManager& get();
        TSharedPtr<sf::Texture> loadTexture(const std::string& path);
        void cleanUp();
        void setRootDirectory(const std::string& directory);

    protected:
        AssetManager();

    private:
        static TUniquePtr<AssetManager> s_assetManager;
        TMap<std::string, TSharedPtr<sf::Texture>> m_loadedTextureMap;
        std::string m_rootDirectory;
    };
}