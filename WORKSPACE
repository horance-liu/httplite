workspace(name = "httplite")

# curl -L https://github.com/horance-liu/cub/archive/8fabbf1313583080863fea52a6c9b1ff6e1cee91.tar.gz | sha256sum
http_archive(
    name = "libcub",
    sha256 = "2841c3370f68ec91578e93ca168ad4416152af1bb2d30975730c69134128191a",
    strip_prefix = "cub-8fabbf1313583080863fea52a6c9b1ff6e1cee91",
    urls = [
        "https://github.com/horance-liu/cub/archive/8fabbf1313583080863fea52a6c9b1ff6e1cee91.tar.gz",
    ],
)

# load all dependencies for cub.
load("@libcub//cub:workspace.bzl", "cub_workspace")
cub_workspace()

