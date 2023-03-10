CC=gcc
SRC=game_of_life.c
DOCKER=podman

game_of_life: $(SRC)
	$(CC) -o game_of_life $(SRC)

.PHONY: debug

debug: $(SRC)
	$(CC) -ggdb -o game_of_life $(SRC)

.PHONY: docker_build

docker_build: Dockerfile.debug Dockerfile.run
	$(DOCKER) build -t game_of_life_debug:latest -f Dockerfile.debug
	$(DOCKER) build -t game_of_life_run:latest -f Dockerfile.run
