BUILD_DIR = "./build/"
BIN_DIR = "./bin/"
APP = "app"

build:
	cmake -S ./ -B ${BUILD_DIR}
	cmake --build ${BUILD_DIR}

run:
	( \
		cd ${BIN_DIR}; \
		./${APP}; \
	)

clean:
	rm -rf ${BIN_DIR}
	rm -rf ${BUILD_DIR}
