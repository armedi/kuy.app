<template>
  <section class="flex items-center mt-12">
    <div class="md:flex w-full p-6 sm:p-8 lg:p-10">
      <div class="md:flex-grow mx-2 sm:mx-4 lg:mx-6">
        <label for="link" class="sr-only">Link</label>
        <div class="relative rounded-md shadow-sm">
          <input
            id="link"
            class="form-input block w-full py-3 text-base leading-6 sm:leading-5"
            placeholder="Shorten your link"
          />
        </div>
      </div>
      <span
        class="block rounded-md shadow-sm mx-2 sm:mx-4 lg:mx-6 mt-2 md:mt-0"
      >
        <button
          type="button"
          class="inline-flex items-center justify-center w-full px-16 py-3 border border-transparent text-base leading-6 rounded-md text-white bg-indigo-600 hover:bg-indigo-500 focus:outline-none focus:border-indigo-700 focus:shadow-outline-indigo active:bg-indigo-700 transition ease-in-out duration-150"
        >
          Shorten
        </button>
      </span>
    </div>
  </section>
</template>

<script lang="ts">
import { defineComponent } from "vue";

export default defineComponent({
  name: "LinkInput"
});
</script>

<style scoped>
section {
  min-height: 10rem;
  background-color: #0d1836;
}

input,
button {
  height: 50px;
}
</style>
