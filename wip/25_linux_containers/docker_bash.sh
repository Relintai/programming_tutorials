
#podman run -i -t -v <absolute path>:/root/project -w /root/project godot-linux:bs /bin/bash


podman run -i -t -v $(pwd)/:/root/project -w /root/project mt_container:1 /bin/bash


