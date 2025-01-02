#!/usr/bin/python3

import subprocess

def run_process_and_capture_output(command):
    try:
        # Run the command and capture the output
        result = subprocess.run(
            command,          # The command to run (list of arguments)
            stdout=subprocess.PIPE,  # Capture standard output
            stderr=subprocess.PIPE,  # Capture standard error (optional)
            text=True,        # Decode output as text (string)
            check=True        # Raise exception on non-zero exit code
        )
        # Return the captured output
        return result.stdout
    except subprocess.CalledProcessError as e:
        print(f"Command failed with exit code {e.returncode}")
        print(f"Error output: {e.stderr}")
        return None

# Example usage
if __name__ == "__main__":
    totalOps = 1024 * 1024 * 1024 * 1024

    numOps = 1024

    while (numOps <= 1024 * 1024 * 1024):
        iterCount = totalOps / numOps

        total_elapsed = 0

        for i in range(1):
            command = ["./test", str(numOps), str(iterCount)]  # Replace with your desired command
            output = run_process_and_capture_output(command)
            if output:
                total_elapsed = total_elapsed + int(output)

        elapsedPerRun = total_elapsed / 1

        print(f"{numOps}, {elapsedPerRun}")

        numOps = numOps * 2

