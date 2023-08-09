
# Dockerのgccサンプルコード

実行コマンド

```bash
docker pull gcc
docker build -t mygcc .
docker run -it --rm -v ${PWD}:/mnt mygcc gcc main.c
docker run -it --rm -v ${PWD}:/mnt mygcc ./a.out
```

もしくは

```bash
docker compose up -d
docker compose exec mygcc gcc main.c
docker compose exec mygcc ./a.out
docker compose down
```
