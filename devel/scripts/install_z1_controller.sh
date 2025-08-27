
RUN mkdir -p ~/git/
cd ~/git/ && git clone https://github.com/unitreerobotics/z1_controller.git --recursive
cd ~/git/z1_controller
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel $(nproc)
