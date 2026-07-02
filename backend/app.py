from flask import Flask, request, jsonify
from flask_cors import CORS
import subprocess
import os



app = Flask(__name__)
CORS(
    app,
    resources={r"/*": {"origins": "http://127.0.0.1:5500"}}
)



@app.route("/")
def home():
    return "Autocomplete Engine Backend is Running!"
@app.route("/search", methods=["GET"])
def search():

    query = request.args.get("q")

    if not query:
        return jsonify({"error": "No query provided"}), 400

    try:
        EXECUTABLE = "./main" if os.name != "nt" else "main.exe"
        result = subprocess.run(
                [EXECUTABLE, query],
                capture_output=True,
                text=True,
                cwd="."
        )

        output = result.stdout.strip().splitlines()

        if not output:
            return jsonify({"results": []})

        search_time = ""
        matches = ""
        results = []

        for line in output:

            if line.startswith("TIME:"):
                search_time = line.replace("TIME:", "")

            elif line.startswith("Matches Found"):
                matches = line.split(":")[1].strip()

            elif "|" in line:
                word, freq = line.split("|")

                results.append({
                    "word": word,
                    "frequency": int(freq)
                })

        return jsonify({
            "query": query,
            "matches": matches,
            "time_microseconds": search_time,
            "results": results
        })

    except Exception as e:
        return jsonify({"error": str(e)})


if __name__ == "__main__":
    app.run(debug=True, use_reloader=False)