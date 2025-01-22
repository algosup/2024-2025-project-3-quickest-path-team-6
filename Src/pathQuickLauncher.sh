SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

osascript -e "tell application \"Terminal\" to do script \"cd '$SCRIPT_DIR/Server' && ./startServer.sh; exec bash\""
osascript -e "tell application \"Terminal\" to do script \"cd '$SCRIPT_DIR/Client' && ./startClient.sh; exec bash\""