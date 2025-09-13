//
// Created by gamerpuppy on 6/24/2021.
//

#ifndef STS_LIGHTSPEED_CHARACTERCLASSES_H
#define STS_LIGHTSPEED_CHARACTERCLASSES_H

#include <cstdint>
#include <algorithm>
#include <array>
#include <cassert>
#include <string>

namespace sts {

    enum class CharacterClass : std::uint8_t {
        IRONCLAD=0,
        SILENT,
        DEFECT,
        WATCHER,
        INVALID,
    };

    static constexpr const char* characterClassNames[] = {"Ironclad","Silent","Defect","Watcher", "Invalid"};
    static constexpr const char* characterClassEnumNames[] = {"IRONCLAD","SILENT","DEFECT","WATCHER", "INVALID"};

    static const char* getCharacterClassName(CharacterClass cc) {
        return characterClassNames[static_cast<int>(cc)];
    }

    static const CharacterClass getCharacterClassFromEnumName(std::string name) {
        auto it = std::find(std::begin(characterClassEnumNames), std::end(characterClassEnumNames), name);
        assert(it != std::end(characterClassEnumNames));
        auto idx = it - std::begin(characterClassEnumNames);
        return static_cast<CharacterClass>(idx);
    }

}

#endif //STS_LIGHTSPEED_CHARACTERCLASSES_H
