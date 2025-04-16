Game Ai mechanics based on ECS methodology with Catch2 testing and Qt ui


Building


- For building with Qt (drawing_layer) run command on MacOS:

    ~/Qt/Tools/CMake/CMake.app/Contents/bin/cmake .. -DCMAKE_PREFIX_PATH=~/Qt/6.2.4/macos

- Or 

    cmake .. -DCMAKE_PREFIX_PATH=~/Qt/6.2.4/macos

- For building without Qt (drawing_layer) run command on MacOS:

    cmake ..


Rules:

- std::vector<> ends with s. For example std::vector<t_component> names as t_components.

- std::span ends with _holder. For example std::span<t_component> names as t_component_holder.
