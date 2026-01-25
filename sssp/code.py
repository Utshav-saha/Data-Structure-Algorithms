import sys

def solve_westeros_puzzle():
    poem = """
    "In the age of broken kingdoms
    ----------
    not all speech was spoken with tongues :) ]<
    -1 < -3 ?
    -1 * -3 <= -3 * -1 ?
    The maesters of old wrote in marks and scars
    ----- <----- (where is the arrow going?)
    -----> (oh its coming back!)
    a script few dared to read
    Beware traveler
    In this war of signs banners fly under the wrong houses
    >>>+ (awww a baby dragon!)
    What once commanded advance now whispers retreat
    [<<<< (is this dragon a little bigger?)
    ----------
    Brackets stand guard where blades once marched.
    -3
    What should add now takes away.
    +++++++++++++ (look! a fench!)
    Many have stared at the writing and seen only madness.
    ----------------
    A jumble of scratches left by a dying realm.
    +++++++++++++++++ (why so many fenches.)"

    This part of the script was found inside a gold mine,
    located on the western coast of Casterly Rock.

    "Only those who notice that the realm’s symbols have changed their loyalties
    ++++++++
    will hear the true message stirring beneath the chaos.
    +++++ For in this land as in Westeros.
    +++++ The truth is not gone.
    It is merely wearing the wrong sigil"
    """

    # --- 1. The Westeros Logic ---
    # > becomes <
    # < becomes >
    # + becomes -
    # - becomes +
    swap_map = {
        '>': '<',
        '<': '>',
        '+': '-',
        '-': '+',
        '[': '[',
        ']': ']',
        '.': '.'
    }

    # --- 2. Extraction & Cleaning ---
    raw_code = ""
    
    # We process the poem line by line to filter out the "smiley face" trap
    lines = poem.split('\n')
    for line in lines:
        # SKIP the trap line with the smiley face
        if ":)" in line:
            continue
            
        for char in line:
            if char in swap_map:
                raw_code += swap_map[char]

    # FORCE FIX: The poem is missing the final closing bracket found in the "North".
    # The loop starts with [ but never ends. We append ']' to close it.
    raw_code += "]" 

    print(f"Extracted Code Length: {len(raw_code)}")
    print("Executing Code...\n--- OUTPUT START ---")

    # --- 3. Robust Brainfuck Interpreter ---
    tape = [0] * 30000
    pointer = 100  # Start at 100 to prevent '<<<' from going out of bounds (Crash fix #2)
    code_ptr = 0
    
    # Map loops
    loop_map = {}
    temp_stack = []
    
    for i, cmd in enumerate(raw_code):
        if cmd == '[':
            temp_stack.append(i)
        elif cmd == ']':
            if temp_stack:
                start = temp_stack.pop()
                loop_map[start] = i
                loop_map[i] = start
            else:
                # If we hit a stray ], just point it to itself (no-op) to prevent crash
                loop_map[i] = i 

    output_buffer = ""

    while code_ptr < len(raw_code):
        command = raw_code[code_ptr]

        if command == '>':
            pointer += 1
        elif command == '<':
            pointer -= 1
        elif command == '+':
            tape[pointer] = (tape[pointer] + 1) % 256
        elif command == '-':
            tape[pointer] = (tape[pointer] - 1) % 256
        elif command == '.':
            output_buffer += chr(tape[pointer])
        elif command == '[':
            if tape[pointer] == 0:
                # If logic is broken/missing, break loop instead of crashing
                if code_ptr in loop_map:
                    code_ptr = loop_map[code_ptr]
                else:
                    break
        elif command == ']':
            if tape[pointer] != 0:
                if code_ptr in loop_map:
                    code_ptr = loop_map[code_ptr]
                else:
                    break
        
        code_ptr += 1

    print(output_buffer)
    print("\n--- OUTPUT END ---")

if __name__ == "__main__":
    solve_westeros_puzzle()